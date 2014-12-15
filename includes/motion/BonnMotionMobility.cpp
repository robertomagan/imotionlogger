//
// Copyright (C) 2005 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#include "BonnMotionMobility.h"
#include "FWMath.h"

BonnMotionMobility::BonnMotionMobility() {
	is3D = false;
	currentLine = -1;
}

BonnMotionMobility::~BonnMotionMobility() {
}

void BonnMotionMobility::initialize(int nodeId, BonnMotionFile bmFile) {

	line = bmFile.getLine(nodeId);
	currentLine = 0;

}

void BonnMotionMobility::setInitialPosition() {
	//const BonnMotionFile::Line& vec = line;
	if (line.size() >= 3) {
		lastPosition.x = line[1];
		lastPosition.y = line[2];
	}

	targetPosition = lastPosition;
//	for (int i = 0; i < line.size(); i++){
//		printf("line %d -> %f\n",i,line[i]);
//	}
}

void BonnMotionMobility::setTargetPosition() {

	if (currentLine + (is3D ? 3 : 2) >= (int) line.size()) {
		nextChange = -1;
		stationary = true;
		targetPosition = lastPosition;
		return;
	}
//	for (int i = 0; i < line.size(); i++){
//			printf("line %d -> %f\n",i,line[i]);
//		}

	nextChange = line[currentLine];
	targetPosition.x = line[currentLine + 1];
	targetPosition.y = line[currentLine + 2];
	targetPosition.z = is3D ? line[currentLine + 3] : 0;
	currentLine += (is3D ? 4 : 3);
	printf("t: %f -> target (%f,%f,%f)\n",nextChange,targetPosition.x,targetPosition.y,targetPosition.z);
}
