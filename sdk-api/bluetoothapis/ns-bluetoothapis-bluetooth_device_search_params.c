typedef struct _BLUETOOTH_DEVICE_SEARCH_PARAMS {
  DWORD  dwSize;
  BOOL   fReturnAuthenticated;
  BOOL   fReturnRemembered;
  BOOL   fReturnUnknown;
  BOOL   fReturnConnected;
  BOOL   fIssueInquiry;
  UCHAR  cTimeoutMultiplier;
  HANDLE hRadio;
} BLUETOOTH_DEVICE_SEARCH_PARAMS;