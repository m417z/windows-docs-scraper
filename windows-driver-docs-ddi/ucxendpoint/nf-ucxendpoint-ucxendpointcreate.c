NTSTATUS UcxEndpointCreate(
  [in]           UCXUSBDEVICE           UsbDevice,
  [out]          PUCXENDPOINT_INIT      *EndpointInit,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          UCXENDPOINT            *Endpoint
);