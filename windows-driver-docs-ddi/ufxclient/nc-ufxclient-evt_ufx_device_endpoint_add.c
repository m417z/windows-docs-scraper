EVT_UFX_DEVICE_ENDPOINT_ADD EvtUfxDeviceEndpointAdd;

NTSTATUS EvtUfxDeviceEndpointAdd(
  [in]      UFXDEVICE unnamedParam1,
  [in]      const PUSB_ENDPOINT_DESCRIPTOR unnamedParam2,
  [in, out] PUFXENDPOINT_INIT unnamedParam3
)
{...}