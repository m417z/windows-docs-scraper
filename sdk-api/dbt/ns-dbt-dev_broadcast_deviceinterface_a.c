typedef struct _DEV_BROADCAST_DEVICEINTERFACE_A {
  DWORD dbcc_size;
  DWORD dbcc_devicetype;
  DWORD dbcc_reserved;
  GUID  dbcc_classguid;
  char  dbcc_name[1];
} DEV_BROADCAST_DEVICEINTERFACE_A, *PDEV_BROADCAST_DEVICEINTERFACE_A;