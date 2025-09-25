typedef struct _WDF_FILEOBJECT_CONFIG {
  ULONG                      Size;
  PFN_WDF_DEVICE_FILE_CREATE EvtDeviceFileCreate;
  PFN_WDF_FILE_CLOSE         EvtFileClose;
  PFN_WDF_FILE_CLEANUP       EvtFileCleanup;
  WDF_TRI_STATE              AutoForwardCleanupClose;
  WDF_FILEOBJECT_CLASS       FileObjectClass;
} WDF_FILEOBJECT_CONFIG, *PWDF_FILEOBJECT_CONFIG;