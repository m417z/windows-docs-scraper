typedef struct _WDF_FDO_EVENT_CALLBACKS {
  ULONG                                       Size;
  PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtDeviceFilterAddResourceRequirements;
  PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtDeviceFilterRemoveResourceRequirements;
  PFN_WDF_DEVICE_REMOVE_ADDED_RESOURCES       EvtDeviceRemoveAddedResources;
} WDF_FDO_EVENT_CALLBACKS, *PWDF_FDO_EVENT_CALLBACKS;