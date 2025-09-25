typedef struct _WSD_PORT_TYPE {
  DWORD             EncodedName;
  DWORD             OperationCount;
  WSD_OPERATION     *Operations;
  WSD_PROTOCOL_TYPE ProtocolType;
} WSD_PORT_TYPE;