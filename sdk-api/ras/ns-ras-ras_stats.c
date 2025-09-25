typedef struct _RAS_STATS {
  DWORD dwSize;
  DWORD dwBytesXmited;
  DWORD dwBytesRcved;
  DWORD dwFramesXmited;
  DWORD dwFramesRcved;
  DWORD dwCrcErr;
  DWORD dwTimeoutErr;
  DWORD dwAlignmentErr;
  DWORD dwHardwareOverrunErr;
  DWORD dwFramingErr;
  DWORD dwBufferOverrunErr;
  DWORD dwCompressionRatioIn;
  DWORD dwCompressionRatioOut;
  DWORD dwBps;
  DWORD dwConnectDuration;
} RAS_STATS, *PRAS_STATS;