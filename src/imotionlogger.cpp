//============================================================================
// Name        : imotion.cpp
// Author      : rmagan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include "lcm/lcmthread.h"
#include <fstream>
#include <signal.h>
#include <sys/time.h>
#include <cstring>

using namespace std;

volatile sig_atomic_t interrupt = 0;
void signal_callback_handler(int signum);

int main(int argc, char * argv[]) {
	signal(SIGINT, signal_callback_handler);

	if (argc < 4) {

		printf("\nUse: ./imotionlogger <wait_time(ms)> <path_log_file> <lcm_channel_1> <lcm_channel_2> ... <lmc_channel_n>\n");
		printf("Erro: at least one LCM_channel must be introduced :( \n");
		return 1;

	} else {

		long int waitTime = atoi(argv[1]);

		// path to save the logs
		string path(argv[2]);

		std::vector<string> lcmChannels;

		for (int i = 3; i < argc; i++) {
			lcmChannels.push_back(argv[i]);
			cout << "Channel " << lcmChannels.back() << " read from command line ..." << endl;
		}

		// List of node obstacles retrieved by LCM-tracking system.
		map<UInt8, Node> listNodesTRACK;

		// List of node obstacles retrieved by the TARGET channel
		map<UInt8, Node> listNodesTARGET;

		/** LCM Listener */
		LCMThread lcmThreadTRACK;
		lcmThreadTRACK.setLCMEngine("udpm://239.255.76.67:7667?ttl=1", lcmChannels[0]);
		lcmThreadTRACK.startInternalThread();
		lcmThreadTRACK.getLcmHandler()->setLcmMessageReceived(false);

		LCMThread lcmThreadTARGET;
		lcmThreadTARGET.setLCMEngine("udpm://239.255.76.67:7667?ttl=1", lcmChannels[1]);
		lcmThreadTARGET.startInternalThread();
		lcmThreadTARGET.getLcmHandler()->setLcmMessageReceived(false);

		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, 80, "%d%m%Y_%H%M%S", timeinfo);
		std::string str(buffer);

		string trackFileLogName = path + lcmChannels[0] + "_" + buffer + ".log";
		string targetFileLogName = path + lcmChannels[1] + "_" + buffer + ".log";

		ofstream trackFileLog(&trackFileLogName[0]);
		ofstream targetFileLog(&targetFileLogName[0]);

		if (!trackFileLog.is_open()) {
			cout << "The file " << trackFileLog << "Could not be created/opened ..." << endl;
			return 1;
		}
		if (!targetFileLog.is_open()) {
			cout << "The file " << targetFileLog << "Could not be created/opened ..." << endl;
			return 1;
		}

		// To set the timestamp
		struct timeval tp;

		while (true) {

			/*  */
			if (!interrupt) {
				/** LCM related Node information */
				//To get the other nodes locations through LCM - from tracking system channel
				listNodesTRACK = lcmThreadTRACK.getLcmHandler()->retrieveNodeList();

				listNodesTARGET = lcmThreadTARGET.getLcmHandler()->retrieveNodeList();

				if (listNodesTRACK.size() != 0 && lcmThreadTRACK.getLcmHandler()->isLcmMessageReceived()) {
					printf("Retrieved %d nodes from tracking system ...\n", listNodesTRACK.size());

					// Timestamp
					gettimeofday(&tp, NULL);
					UInt64 ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
					trackFileLog << ms;
					cout << ms;

					for (map<UInt8, Node>::iterator it = listNodesTRACK.begin(); it != listNodesTRACK.end(); it++) {

						// Get the node from
						Node nodeAux = it->second;

						// Write on file
						trackFileLog << " " << nodeAux.getTimestamp() << " " << nodeAux.getId() << " " << nodeAux.getPosition().GetX() << " " << nodeAux.getPosition().GetY() << " " << nodeAux.getPosition().GetZ();
						trackFileLog << " " << nodeAux.getOrientation().GetW() << " " << nodeAux.getOrientation().GetX() << " " << nodeAux.getOrientation().GetY() << " "
								<< nodeAux.getOrientation().GetZ() << " ";
						trackFileLog << nodeAux.getVelocity();
						cout << " " << nodeAux.getId() << " " << nodeAux.getPosition().GetX() << " " << nodeAux.getPosition().GetY() << " ";

					}

					trackFileLog << endl;
					cout << endl;
				}
				//
				lcmThreadTRACK.getLcmHandler()->setLcmMessageReceived(false);

				if (listNodesTARGET.size() != 0 && lcmThreadTARGET.getLcmHandler()->isLcmMessageReceived()) {
					printf("Retrieved %d nodes from TARGET channel ...\n", listNodesTARGET.size());

					// Timestamp
					gettimeofday(&tp, NULL);
					UInt64 ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
					targetFileLog << ms;
					cout << ms;

					for (map<UInt8, Node>::iterator it = listNodesTARGET.begin(); it != listNodesTARGET.end(); it++) {

						// Get the node from
						Node nodeAux = it->second;

						// Write on file
						targetFileLog << " " << nodeAux.getTimestamp() <<" " << nodeAux.getId() << " " << nodeAux.getPosition().GetX() << " " << nodeAux.getPosition().GetY() << " " << nodeAux.getPosition().GetZ();
						targetFileLog << " " << nodeAux.getOrientation().GetW() << " " << nodeAux.getOrientation().GetX() << " " << nodeAux.getOrientation().GetY() << " "
								<< nodeAux.getOrientation().GetZ() << " ";
						targetFileLog << nodeAux.getVelocity();
						cout << " " << nodeAux.getId() << " " << nodeAux.getPosition().GetX() << " " << nodeAux.getPosition().GetY() << " ";

					}

					targetFileLog << endl;
					cout << endl;
				}
				//
				lcmThreadTARGET.getLcmHandler()->setLcmMessageReceived(false);

			} else {
				// I there was a ctrl+c signal
				trackFileLog.close();
				targetFileLog.close();
				printf("\nCTRL+C - Closing loggers files and EXIT\n");
				exit(1);
			}

			usleep(waitTime * 1000);

		}

		return 0;
	}
}

void signal_callback_handler(int signum) {
	//printf("Caught signal %d\n", signum);
	// Cleanup and close up stuff here
	interrupt = true;

	// Terminate program
	//exit(signum);
}
