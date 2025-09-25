typedef struct FWPS_TRANSPORT_SEND_PARAMS1_ {
  UCHAR      *remoteAddress;
  SCOPE_ID   remoteScopeId;
  WSACMSGHDR *controlData;
  ULONG      controlDataLength;
  UCHAR      *headerIncludeHeader;
  ULONG      headerIncludeHeaderLength;
} FWPS_TRANSPORT_SEND_PARAMS1;