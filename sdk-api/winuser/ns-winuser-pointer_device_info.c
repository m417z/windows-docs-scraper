typedef struct tagPOINTER_DEVICE_INFO {
  DWORD               displayOrientation;
  HANDLE              device;
  POINTER_DEVICE_TYPE pointerDeviceType;
  HMONITOR            monitor;
  ULONG               startingCursorId;
  USHORT              maxActiveContacts;
  WCHAR               productString[POINTER_DEVICE_PRODUCT_STRING_MAX];
} POINTER_DEVICE_INFO;