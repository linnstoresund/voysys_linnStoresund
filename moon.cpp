using namespace std;


#include "Vec3.h"
#include "moon.h"

// Explicit constructor
moon::moon() {
	position = { 0, 0, 0 };
	velocity = { 0, 0, 0 };
}

// Constructor
moon::moon(int xPos, int yPos, int zPos)
{
	position = { xPos, yPos, zPos };
	velocity = { 0, 0, 0 };
}


// Get components from moon objects
int moon::getX() const {
	return position.getX();
}

int moon::getY() const {
	return position.getY();
}

int moon::getZ() const {
	return position.getZ();
}


//returns the velocity with a 3D-vector
Vec3 moon::getVelocity() const{
	return velocity;
}

//returns the sum of potential and velocity
int moon::getEnergy() const {
	int sum, pot, kin = 0;
	pot = abs(position.getX()) + abs(position.getY()) + abs(position.getZ());
	kin = abs(getVelocity().getX()) + abs(getVelocity().getY()) + abs(getVelocity().getZ());
	sum = pot * kin;

	return sum;
}


//update the position with the velocity
void moon::updatePosition(){
	position.addX(getVelocity().getX());
	position.addY(getVelocity().getY());
	position.addZ(getVelocity().getZ());
}



void moon::addGravity(const moon &m1, const moon &m2, const moon &m3) {

	//comparing X with the first moon
	if (position.getX() != m1.getX()) {
		if (position.getX() < m1.getX()) {
		velocity.addX(1);

	}
		else if (position.getX() > m1.getX()) {
		velocity.addX(-1);
	}
	}

	//comparing Y with the first moon
	if (position.getY() != m1.getY()) {
		if (position.getY() < m1.getY()) {
			velocity.addY(1);

		}
		else if (position.getY() > m1.getY()) {
			velocity.addY(-1);
		}
	}

	//comparing Z with the first moon
	if (position.getZ() != m1.getZ()) {
		if (position.getZ() < m1.getZ()) {
			velocity.addZ(1);

		}
		else if (position.getZ() > m1.getZ()) {
			velocity.addZ(-1);
		}
	}

	//comparing X with the second moon
	if (position.getX() != m2.getX()) {
		if (position.getX() < m2.getX()) {
		velocity.addX(1);
		}
		else if (position.getX() > m2.getX()) {
		velocity.addX(-1);
		}
	}

	//comparing Y with the second moon
	if (position.getY() != m2.getY()) {
		if (position.getY() <= m2.getY()) {
			velocity.addY(1);
		}

		else if (position.getY() > m2.getY()) {
			velocity.addY(-1);
		}
	}


	//comparing Z with the second moon
	if (position.getZ() != m2.getZ()) {
		if (position.getZ() < m2.getZ()) {
			velocity.addZ(1);

		}
		else if (position.getZ() > m2.getZ()) {
			velocity.addZ(-1);
		}
	}

	//comparing X with the third moon
	if (position.getX() != m3.getX()) {
		if (position.getX() < m3.getX()) {
			velocity.addX(1);
		}
		else if (position.getX() > m3.getX()) {
			velocity.addX(-1);
		}
	}

	//comparing Y with the third moon
	if (position.getY() != m3.getY()) {
		if (position.getY() <= m3.getY()) {
			velocity.addY(1);
		}

		else if (position.getY() > m3.getY()) {
			velocity.addY(-1);
		}
	}


	//comparing Z with the third moon
	if (position.getZ() != m3.getZ()) {
		if (position.getZ() < m3.getZ()) {
			velocity.addZ(1);

		}
		else if (position.getZ() > m3.getZ()) {
			velocity.addZ(-1);
		}
	}


}


