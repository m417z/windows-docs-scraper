typedef struct _WDF_PDO_EVENT_CALLBACKS {
  ULONG                                      Size;
  PFN_WDF_DEVICE_RESOURCES_QUERY             EvtDeviceResourcesQuery;
  PFN_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY EvtDeviceResourceRequirementsQuery;
  PFN_WDF_DEVICE_EJECT                       EvtDeviceEject;
  PFN_WDF_DEVICE_SET_LOCK                    EvtDeviceSetLock;
  PFN_WDF_DEVICE_ENABLE_WAKE_AT_BUS          EvtDeviceEnableWakeAtBus;
  PFN_WDF_DEVICE_DISABLE_WAKE_AT_BUS         EvtDeviceDisableWakeAtBus;
  PFN_WDF_DEVICE_REPORTED_MISSING            EvtDeviceReportedMissing;
} WDF_PDO_EVENT_CALLBACKS, *PWDF_PDO_EVENT_CALLBACKS;