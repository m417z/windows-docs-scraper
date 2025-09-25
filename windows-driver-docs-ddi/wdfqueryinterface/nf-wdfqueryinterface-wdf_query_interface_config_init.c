VOID WDF_QUERY_INTERFACE_CONFIG_INIT(
  [out]          PWDF_QUERY_INTERFACE_CONFIG                    InterfaceConfig,
  [in]           PINTERFACE                                     Interface,
  [in]           const GUID                                     *InterfaceType,
  [in, optional] PFN_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST EvtDeviceProcessQueryInterfaceRequest
);