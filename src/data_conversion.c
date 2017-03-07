// This file implements the data conversion between 8 bits data packets received from the 
// RF receiver and its corresponding floating point numbers.(Written by Dominic) The data is 
// further put into data structure that will be send to  the host computer for telemetry purposes.

#include "data_structures.h"

// Declares a function that convertes the data received through RF communication
// received in packets of bytes to its corresponding float numbers and puts all the data
// into the structure to send the data to the host
data_conversion(&rf_data_packet, &host_data_packet){
	host_data_packet->roll = rf_data_packet->roll.value;
	host_data_packet->pitch = rf_data_packet->pitch.value;
	host_data_packet->yaw_vel = rf_data_packet->yaw_vel.value;
}
