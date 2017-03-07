// This file specifies the interface with the host computer.
// It uses UART communication protocol to propagates the data 
// received wirelessly from the communicaitn module.

#ifndef __HOST_COMPUTER_INTERFACE_H
#define __HOST_COMPUTER_INTERFACE_H

//This function initializes UART used for the comunication with the host computer
void host_comms_init(void);

// In this function sending the data to the host computer is performed
void send_host_packet(host_data_packet_t* host_data_packet);


#endif