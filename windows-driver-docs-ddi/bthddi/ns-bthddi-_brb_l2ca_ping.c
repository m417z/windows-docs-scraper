struct _BRB_L2CA_PING {
  BRB_HEADER Hdr;
  BTH_ADDR   BtAddress;
  UCHAR      PingRequestLength;
  UCHAR      PingRequestData[MAX_L2CAP_PING_DATA_LENGTH];
  UCHAR      PingResponseLength;
  UCHAR      PingResponseData[MAX_L2CAP_PING_DATA_LENGTH];
};