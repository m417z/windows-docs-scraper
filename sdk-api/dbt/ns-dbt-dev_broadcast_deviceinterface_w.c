typedef struct _DEV_BROADCAST_DEVICEINTERFACE_W {
  DWORD   dbcc_size;
  DWORD   dbcc_devicetype;
  DWORD   dbcc_reserved;
  GUID    dbcc_classguid;
  wchar_t dbcc_name[1];
} DEV_BROADCAST_DEVICEINTERFACE_W, *PDEV_BROADCAST_DEVICEINTERFACE_W;