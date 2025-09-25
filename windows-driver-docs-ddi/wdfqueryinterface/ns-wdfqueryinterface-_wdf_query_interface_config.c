typedef struct _WDF_QUERY_INTERFACE_CONFIG {
  ULONG                                          Size;
  PINTERFACE                                     Interface;
  const GUID                                     *InterfaceType;
  BOOLEAN                                        SendQueryToParentStack;
  PFN_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST EvtDeviceProcessQueryInterfaceRequest;
  BOOLEAN                                        ImportInterface;
} WDF_QUERY_INTERFACE_CONFIG, *PWDF_QUERY_INTERFACE_CONFIG;