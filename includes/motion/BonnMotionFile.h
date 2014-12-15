/*
 * BonnMotionFile.h
 *
 *  Created on: 24/11/2014
 *      Author: roberto
 */

#ifndef MOTION_BONNMOTIONFILE_H_
#define MOTION_BONNMOTIONFILE_H_

#include <stdio.h>
#include <stddef.h>
#include <string>
#include <vector>
#include <list>
#include <map>

/**
 * Represents a BonnMotion file's contents.
 * @see BonnMotionFileCache, BonnMotionMobility
 */
class BonnMotionFile {

public:
	typedef std::vector<double> Line;
	typedef std::map<int,Line> LineMap;
	Line line;
	LineMap lines;

	Line getLine(int nodeId);
	void parseFile(const char *filename);

	BonnMotionFile();
	~BonnMotionFile();
};

#endif /* MOTION_BONNMOTIONFILE_H_ */

