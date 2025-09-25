typedef struct _BTH_L2CAP_EVENT_INFO {
  BTH_ADDR bthAddress;
  USHORT   psm;
  UCHAR    connected;
  UCHAR    initiated;
} BTH_L2CAP_EVENT_INFO, *PBTH_L2CAP_EVENT_INFO;