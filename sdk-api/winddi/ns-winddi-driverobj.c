typedef struct _DRIVEROBJ {
  PVOID       pvObj;
  FREEOBJPROC pFreeProc;
  HDEV        hdev;
  DHPDEV      dhpdev;
} DRIVEROBJ;