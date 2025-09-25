EVT_WDF_DEVICE_PROCESS_QUERY_INTERFACE_REQUEST EvtWdfDeviceProcessQueryInterfaceRequest;

NTSTATUS EvtWdfDeviceProcessQueryInterfaceRequest(
  [in]      WDFDEVICE Device,
  [in]      LPGUID InterfaceType,
  [in, out] PINTERFACE ExposedInterface,
  [in, out] PVOID ExposedInterfaceSpecificData
)
{...}