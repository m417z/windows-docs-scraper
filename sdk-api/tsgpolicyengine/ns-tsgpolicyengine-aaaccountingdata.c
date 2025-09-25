typedef struct __MIDL___MIDL_itf_tsgpolicyengine_0000_0000_0003 {
  BSTR          userName;
  BSTR          clientName;
  AAAuthSchemes authType;
  BSTR          resourceName;
  int           portNumber;
  BSTR          protocolName;
  int           numberOfBytesReceived;
  int           numberOfBytesTransfered;
  BSTR          reasonForDisconnect;
  GUID          mainSessionId;
  int           subSessionId;
} AAAccountingData;