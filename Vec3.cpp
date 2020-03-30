#define _USE_MATH_DEFINES

#include "Vec3.h"

#include <iostream>
#include <vector>       // std::vector
#include <cmath>


// Explicit constructor

Vec3::Vec3()
	: x{ 0 }, y{ 0 }, z{ 0 } {}


// Constructor
Vec3::Vec3(int xIn, int yIn, int zIn)
	: x{ xIn }, y{ yIn }, z{ zIn } {}



Vec3::Vec3(const Vec3& inVec)
	: x{ inVec.getX() }, y{ inVec.getY() }, z{ inVec.getZ() } {}



// Get components
int Vec3::getX() const {
	return x;
}

int Vec3::getY() const {
	return y;
}

int Vec3::getZ() const {
	return z;
}

// Add with in n
void Vec3::addX(int n) {
	x += n;
}

void Vec3::addY(int n) {
	y += n;
}

void Vec3::addZ(int n) {
	z += n;
}


