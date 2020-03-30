#pragma once
#include <cmath>
#include <iostream>

using namespace std;


class Vec3 {
public:
	// Constructors
	Vec3();
	Vec3(int xIn, int yIn, int zIn);
	Vec3(const Vec3& inVec);

	// Decstructor
	~Vec3() = default;

	// Get X, Y or Z component
	int getX() const;
	int getY() const;
	int getZ() const;

	// Add X, Y or Z component
	void addX(int x);
	void addY(int y);
	void addZ(int z);


protected:
	//variables
	int x;
	int y;
	int z;
};


