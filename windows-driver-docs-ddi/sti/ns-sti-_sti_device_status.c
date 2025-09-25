typedef struct _STI_DEVICE_STATUS {
  DWORD dwSize;
  DWORD StatusMask;
  DWORD dwOnlineState;
  DWORD dwHardwareStatusCode;
  DWORD dwEventHandlingState;
  DWORD dwPollingInterval;
} STI_DEVICE_STATUS, *PSTI_DEVICE_STATUS;