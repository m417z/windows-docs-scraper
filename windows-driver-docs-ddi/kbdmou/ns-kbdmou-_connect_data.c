typedef struct _CONNECT_DATA {
  IN PDEVICE_OBJECT ClassDeviceObject;
  IN PVOID          ClassService;
} CONNECT_DATA, *PCONNECT_DATA;