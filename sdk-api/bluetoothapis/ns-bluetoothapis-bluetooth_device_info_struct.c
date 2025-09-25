typedef struct _BLUETOOTH_DEVICE_INFO {
  DWORD             dwSize;
  BLUETOOTH_ADDRESS Address;
  ULONG             ulClassofDevice;
  BOOL              fConnected;
  BOOL              fRemembered;
  BOOL              fAuthenticated;
  SYSTEMTIME        stLastSeen;
  SYSTEMTIME        stLastUsed;
  WCHAR             szName[BLUETOOTH_MAX_NAME_SIZE];
} BLUETOOTH_DEVICE_INFO_STRUCT;