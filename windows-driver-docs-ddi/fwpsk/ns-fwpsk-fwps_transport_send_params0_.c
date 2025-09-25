typedef struct FWPS_TRANSPORT_SEND_PARAMS0_ {
  UCHAR      *remoteAddress;
  SCOPE_ID   remoteScopeId;
  WSACMSGHDR *controlData;
  ULONG      controlDataLength;
} FWPS_TRANSPORT_SEND_PARAMS0;