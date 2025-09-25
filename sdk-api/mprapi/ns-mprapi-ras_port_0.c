typedef struct _RAS_PORT_0 {
  HANDLE             hPort;
  HANDLE             hConnection;
  RAS_PORT_CONDITION dwPortCondition;
  DWORD              dwTotalNumberOfCalls;
  DWORD              dwConnectDuration;
  WCHAR              wszPortName[MAX_PORT_NAME + 1];
  WCHAR              wszMediaName[MAX_MEDIA_NAME + 1];
  WCHAR              wszDeviceName[MAX_DEVICE_NAME + 1];
  WCHAR              wszDeviceType[MAX_DEVICETYPE_NAME + 1];
} RAS_PORT_0, *PRAS_PORT_0;