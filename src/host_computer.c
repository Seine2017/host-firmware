
#include "debug.h"
#include "data_structures.h"

//This function initializes UART used for the comunication with the host computer
void host_comms_init(void){
  init_debug_uart0();
}

// In this function sending the data to the host computer is performed
void send_host_packet(host_data_packet_t* host_data_packet){
  printf("%f %f %f\n", (double)host_data_packet->roll, (double)host_data_packet->pitch, (double)host_data_packet->yaw_vel);
}
