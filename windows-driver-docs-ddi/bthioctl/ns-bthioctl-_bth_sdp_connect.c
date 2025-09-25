typedef struct _BTH_SDP_CONNECT {
  BTH_ADDR        bthAddress;
  ULONG           fSdpConnect;
  HANDLE_SDP_TYPE HANDLE_SDP_FIELD_NAME;
  UCHAR           requestTimeout;
} BTH_SDP_CONNECT, *PBTH_SDP_CONNECT;