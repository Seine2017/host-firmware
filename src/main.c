
#include "rf_transceiver_interface.h"
#include "data_conversion.h"
#include "data_structures.h"

// Define the data packets that will flow through the communication module
// as global variables
rf_data_packet_t rf_data_packet;
host_data_packet_t host_data_packet;


int main() {
  //Initialize all the submodules
  host_comms_init();
  rf_receiver_init();
  SPI_init(); //defined by Kiran
  //sei(); // enable interrups

  // We need to consider timing - at what frequency each communication link
  // operates. We can handle some of the functions in the interrupts.
  // Alternatively, we can set up a clock that will keep track of the internal
  // time in the module and execute the functions at decided frequencies accordingly
  while (1) {

    ///////////////////////////////////// DOWNLINK COMMUNICATION ///////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    
    // Communicate with the RF receiver to obtain the logging data.
    receive_data_packet(&rf_data_packet);

    // Decode the data. Here is the place for some decryption algorithm
    decode_data(&rf_data_packet, &host_data_packet);
	
    // Send data to the RF module to wirelessly transmit the logging data to the host computer.
    send_host_packet(&host_data_packet);

    /////////////////////////////////////////////////////////////////////////////////////////////
  }
}

