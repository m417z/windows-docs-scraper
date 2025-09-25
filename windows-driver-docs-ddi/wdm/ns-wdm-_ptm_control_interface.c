typedef struct _PTM_CONTROL_INTERFACE {
  USHORT                        Size;
  USHORT                        Version;
  PVOID                         Context;
  PINTERFACE_REFERENCE          InterfaceReference;
  PINTERFACE_DEREFERENCE        InterfaceDereference;
  PPTM_DEVICE_QUERY_GRANULARITY QueryGranularity;
  PPTM_DEVICE_QUERY_TIME_SOURCE QueryTimeSource;
  PPTM_DEVICE_ENABLE            Enable;
  PPTM_DEVICE_DISABLE           Disable;
} PTM_CONTROL_INTERFACE, *PPTM_CONTROL_INTERFACE;