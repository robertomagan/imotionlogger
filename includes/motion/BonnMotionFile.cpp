/*
 * BonnMotionFile.cpp
 *
 *  Created on: 24/11/2014
 *      Author: roberto
 */

#include <fstream>
#include <sstream>
#include "BonnMotionFile.h"

BonnMotionFile::BonnMotionFile() {
	// TODO Auto-generated constructor stub

}

BonnMotionFile::~BonnMotionFile() {
	// TODO Auto-generated destructor stub
}

BonnMotionFile::Line BonnMotionFile::getLine(int nodeId) {

//	BonnMotionFile::LineMap::iterator it;
//	for (it = lines.begin(); it != lines.end(); it++) {
//		printf("[getLine] bmFile ID %d, vecLine %f\n", (it->first), (it->second).at(1));
//	}

//	printf("ID %d, value at %f\n",nodeId,lines.at(1).at(1));
//	printf("ID %d, value %f\n",(lines.find(nodeId))->first,((lines.find(nodeId))->second).at(1));

	Line nodeLine;

	// If exist the line (node)
	if (lines.end() != lines.find(nodeId)) {
		nodeLine = lines.at(nodeId);
	} else {
		printf("The nodeId %d does not exists\n", nodeId);
	}

	return nodeLine;

}

void BonnMotionFile::parseFile(const char *filename) {
	std::ifstream in(filename, std::ios::in);
	if (in.fail())
		printf("Cannot open file '%s'", filename);

	std::string line;
	int i = 0;
	while (std::getline(in, line)) {

		BonnMotionFile::Line vecLine;

		std::stringstream linestream(line);
		double d;
		while (linestream >> d)
			vecLine.push_back(d);

		//printf("vecLine value %f of %d line\n",vecLine[1],i);

		lines[i] = vecLine;
		i++;
	}
	in.close();

//	BonnMotionFile::LineMap::iterator it;
//	for (it = lines.begin(); it!= lines.end(); it++){
//		printf("bmFile ID %d, vecLine %f\n",(it->first),(it->second).at(1));
//	}
}

