typedef struct _RAS_PORT_1 {
  HANDLE                 hPort;
  HANDLE                 hConnection;
  RAS_HARDWARE_CONDITION dwHardwareCondition;
  DWORD                  dwLineSpeed;
  DWORD                  dwBytesXmited;
  DWORD                  dwBytesRcved;
  DWORD                  dwFramesXmited;
  DWORD                  dwFramesRcved;
  DWORD                  dwCrcErr;
  DWORD                  dwTimeoutErr;
  DWORD                  dwAlignmentErr;
  DWORD                  dwHardwareOverrunErr;
  DWORD                  dwFramingErr;
  DWORD                  dwBufferOverrunErr;
  DWORD                  dwCompressionRatioIn;
  DWORD                  dwCompressionRatioOut;
} RAS_PORT_1, *PRAS_PORT_1;