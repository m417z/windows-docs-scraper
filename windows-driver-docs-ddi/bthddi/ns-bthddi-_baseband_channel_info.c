typedef struct _BASEBAND_CHANNEL_INFO {
  UCHAR  Transmission_Interval;
  UCHAR  Retransmission_Window;
  UCHAR  AirMode;
  USHORT Rx_Packet_Length;
  USHORT Tx_Packet_Length;
} BASEBAND_CHANNEL_INFO, *PBASEBAND_CHANNEL_INFO;