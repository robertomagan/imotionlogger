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

#ifndef BONN_MOTION_MOBILITY_H
#define BONN_MOTION_MOBILITY_H

#include "BonnMotionFile.h"
#include "Coord.h"

/**
 * @brief Uses the BonnMotion native file format. See NED file for more info.
 *
 * @ingroup mobility
 * @author Andras Varga
 */
class BonnMotionMobility {

public:

	// state
	bool is3D;
	BonnMotionFile::Line line;
	int currentLine;
	double nextChange;
	Coord targetPosition;
	Coord lastPosition;
	bool stationary;



	/** @brief Initializes mobility model parameters. */
	void initialize(int nodeId, BonnMotionFile bmFile);

	/** @brief Initializes the position according to the mobility model. */
	virtual void setInitialPosition();

	/** @brief Overridden from LineSegmentsMobilityBase. */
	virtual void setTargetPosition();

	BonnMotionMobility();

	virtual ~BonnMotionMobility();

	const Coord& getLastPosition() const {
		return lastPosition;
	}

	void setLastPosition(const Coord& lastPosition) {
		this->lastPosition = lastPosition;
	}

	bool isStationary() const {
		return stationary;
	}

	void setStationary(bool stationary) {
		this->stationary = stationary;
	}

	const Coord& getTargetPosition() const {
		return targetPosition;
	}
};

#endif
