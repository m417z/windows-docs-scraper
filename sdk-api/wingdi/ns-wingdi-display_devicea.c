typedef struct _DISPLAY_DEVICEA {
  DWORD cb;
  CHAR  DeviceName[32];
  CHAR  DeviceString[128];
  DWORD StateFlags;
  CHAR  DeviceID[128];
  CHAR  DeviceKey[128];
} DISPLAY_DEVICEA, *PDISPLAY_DEVICEA, *LPDISPLAY_DEVICEA;