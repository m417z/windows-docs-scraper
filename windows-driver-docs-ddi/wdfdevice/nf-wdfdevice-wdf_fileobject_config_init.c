VOID WDF_FILEOBJECT_CONFIG_INIT(
  [out]          PWDF_FILEOBJECT_CONFIG     FileEventCallbacks,
  [in, optional] PFN_WDF_DEVICE_FILE_CREATE EvtDeviceFileCreate,
  [in, optional] PFN_WDF_FILE_CLOSE         EvtFileClose,
  [in, optional] PFN_WDF_FILE_CLEANUP       EvtFileCleanup
);