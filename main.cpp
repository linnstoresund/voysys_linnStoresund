/********** TEST INPUT ************

<x=-7, y=-1, z=6>
<x=6, y=-9, z=-9>
<x=-12, y=2, z=-7>
<x=4, y=-17, z=-12>

Result: 11384

******************************/
#include "Vec3.h"
#include "moon.h"

#include <iostream>
#include <iomanip>

using namespace std;
const int amountTimes = 1;


int main() {
	
	moon moonIo(-7, -1, 6);
	moon moonEuropa(6, -9, -9);
	moon moonGanymede(-12, 2, -7);
	moon moonCallisto(4, -17, -12); 

	
	//First output, step = 0
	//position and velocity for each moon
	//Moon IO
	cout << "After " << 0 << " steps:" << endl;
	cout  << "pos=<x= " << right << setw(2) << moonIo.getX()
		<< left << setw(1) << ", y= " << right << setw(2) << moonIo.getY()
		<< left << setw(1) << ", z= " << right << setw(2) << moonIo.getZ() << ">,";
	cout << " vel=<x= " << right << setw(2) << moonIo.getVelocity().getX()
		<< left << setw(1) << ", y= " << right << setw(2) << moonIo.getVelocity().getY()
		<< left << setw(1) << ", z= " << right << setw(2) << moonIo.getVelocity().getZ() << ">" << endl;

	//Moon Europa
	cout << "pos=<x= " << right << setw(2) << moonEuropa.getX()
		<< left << setw(1) << ", y= " << right << setw(2) << moonEuropa.getY()
		<< left << setw(1) << ", z= " << right << setw(2) << moonEuropa.getZ() << ">,";
	cout << " vel=<x= " << right << setw(2) << moonEuropa.getVelocity().getX()
		<< left << setw(1) << ", y= " << right << setw(2) << moonEuropa.getVelocity().getY()
		<< left << setw(1) << ", z= " << right << setw(2) << moonEuropa.getVelocity().getZ() << ">" << endl;

	//Moon Ganymede
	cout << "pos=<x=" << moonGanymede.getX()
		<< left << setw(1) << ", y=" << right << setw(3) << moonGanymede.getY()
		<< left << setw(1) << ", z= " << right << setw(2) << moonGanymede.getZ() << ">,";
	cout << " vel=<x= " << right << setw(2) << moonGanymede.getVelocity().getX()
		<< left << setw(1) << ", y= " << right << setw(2) << moonGanymede.getVelocity().getY()
		<< left << setw(1) << ", z= " << right << setw(2) << moonGanymede.getVelocity().getZ() << ">" << endl;

	//Moon Callisto
	cout << "pos=<x= " << right << setw(2) << moonCallisto.getX()
		<< left << setw(1) << ", y=" << moonCallisto.getY()
		<< left << setw(1) << ", z=" << right << setw(2)<< moonCallisto.getZ() << ">,";
	cout << " vel=<x= " << right << setw(2) << moonCallisto.getVelocity().getX()
		<< left << setw(1) << ", y= " << right << setw(2) << moonCallisto.getVelocity().getY()
		<< left << setw(1) << ", z= " << right << setw(2) << moonCallisto.getVelocity().getZ() << ">" << endl;
	
	cout << "*" << setfill('-') << setw(51) << "*" << endl;


	//The sum of the energy 
	cout << "Sum of total energy after 0 steps: " << moonIo.getEnergy() << " + " << moonEuropa.getEnergy() << " + " << moonGanymede.getEnergy() << " + " << moonCallisto.getEnergy()
		<< " = " << moonIo.getEnergy() + moonEuropa.getEnergy() + moonGanymede.getEnergy() << endl << endl;


	for (int i = 0; i < amountTimes; i++) {

		int counter = 1;

		while (counter < 1001) {

			//Adding the gravity for each moon 
			moonIo.addGravity(moonEuropa, moonGanymede, moonCallisto);
			moonEuropa.addGravity(moonIo, moonGanymede, moonCallisto);
			moonGanymede.addGravity(moonIo, moonEuropa, moonCallisto);
			moonCallisto.addGravity(moonIo, moonGanymede, moonEuropa);


			//Updating the position depending on the new velocity
			moonIo.updatePosition();
			moonEuropa.updatePosition();
			moonGanymede.updatePosition();
			moonCallisto.updatePosition();
		

			if (counter == 1000) {

				//Print out position and velocity
				cout << "After " << counter << " steps:" << endl;
				//Moon IO 
				cout << "pos=<x= " << right << setw(2) << moonIo.getX()
					<< left << setw(1) << ", y= " << right << setw(2) << moonIo.getY()
					<< left << setw(1) << ", z= " << right << setw(2) << moonIo.getZ() << ">,";
				cout << " vel=<x= " << right << setw(2) << moonIo.getVelocity().getX()
					<< left << setw(1) << ", y= " << right << setw(2) << moonIo.getVelocity().getY()
					<< left << setw(1) << ", z=" << right << setw(1) << moonIo.getVelocity().getZ() << ">" << endl;

				//Moon Europa 
				cout << "pos=<x=" << right << setw(2) << moonEuropa.getX()
					<< left << setw(1) << ", y= " << right << setw(2) << moonEuropa.getY()
					<< left << setw(1) << ", z=" << right << setw(2) << moonEuropa.getZ() << ">,";
				cout << " vel=<x= " << right << setw(2) << moonEuropa.getVelocity().getX()
					<< left << setw(1) << ", y= " << right << setw(2) << moonEuropa.getVelocity().getY()
					<< left << setw(1) << ", z= " << right << setw(2) << moonEuropa.getVelocity().getZ() << ">" << endl;

				//Moon Ganymede
				cout << "pos=<x=" << moonGanymede.getX()
					<< left << setw(1) << ", y=" << right << setw(3) << moonGanymede.getY()
					<< left << setw(1) << ", z= " << right << setw(2) << moonGanymede.getZ() << ">,";
				cout << " vel=<x= " << right << setw(2) << moonGanymede.getVelocity().getX()
					<< left << setw(1) << ", y=" << right << setw(2) << moonGanymede.getVelocity().getY()
					<< left << setw(1) << ", z= " << right << setw(2) << moonGanymede.getVelocity().getZ() << ">" << endl;

				//Moon Callisto
				cout << "pos=<x= " << right << setw(2) << moonCallisto.getX()
					<< left << setw(1) << ", y=" << moonCallisto.getY()
					<< left << setw(1) << ", z=" << right << setw(2) << moonCallisto.getZ() << ">,";
				cout << " vel=<x= " << right << setw(2) << moonCallisto.getVelocity().getX()
					<< left << setw(1) << ", y= " << right << setw(2) << moonCallisto.getVelocity().getY()
					<< left << setw(1) << ", z= " << right << setw(2) << moonCallisto.getVelocity().getZ() << ">"<<endl;
					
				cout << "*" << setfill('-') << setw(51) << "*" << endl;

				//The sum of the energy 
				cout << "Sum of total energy after " << counter << " steps: " << moonIo.getEnergy() << " + " << moonEuropa.getEnergy() << " + " << moonGanymede.getEnergy() << " + " << moonCallisto.getEnergy()
					<< " = " << moonIo.getEnergy() + moonEuropa.getEnergy() + moonGanymede.getEnergy() + moonCallisto.getEnergy() << endl << endl;
			}
			counter++;
		
		}

	}



	return 0;
}




