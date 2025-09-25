typedef struct _RAS_CONNECTION_1 {
  HANDLE   hConnection;
  HANDLE   hInterface;
  PPP_INFO PppInfo;
  DWORD    dwBytesXmited;
  DWORD    dwBytesRcved;
  DWORD    dwFramesXmited;
  DWORD    dwFramesRcved;
  DWORD    dwCrcErr;
  DWORD    dwTimeoutErr;
  DWORD    dwAlignmentErr;
  DWORD    dwHardwareOverrunErr;
  DWORD    dwFramingErr;
  DWORD    dwBufferOverrunErr;
  DWORD    dwCompressionRatioIn;
  DWORD    dwCompressionRatioOut;
} RAS_CONNECTION_1, *PRAS_CONNECTION_1;