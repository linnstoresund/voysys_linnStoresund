#pragma once
/*
	 MOON CLASS
*/

class moon {
public:
	// Constructors
	moon();
	moon(int xPos, int yPos, int zPos);

	// Decstructor
	~moon() = default;

	// Get components
	int getX() const;
	int getY() const;
	int getZ() const;

	//Get velocity and energy for one moon
	Vec3 getVelocity() const;
	int getEnergy() const;

	//update the position from velocity
	void updatePosition();

	//add gravity to each velocity
	//comparing one moon with the other three moons
	void addGravity(const moon &m1,const moon &m2, const moon &m3);


protected:
	Vec3 position;
	Vec3 velocity;
};


