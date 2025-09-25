typedef struct _RAS_SECURITY_INFO {
  DWORD LastError;
  DWORD BytesReceived;
  CHAR  DeviceName[MAX_DEVICE_NAME + 1];
} RAS_SECURITY_INFO, *PRAS_SECURITY_INFO;