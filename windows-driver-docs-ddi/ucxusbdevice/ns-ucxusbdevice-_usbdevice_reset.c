typedef struct _USBDEVICE_RESET {
  USBDEVICE_MGMT_HEADER Header;
  UCXENDPOINT           DefaultEndpoint;
  ULONG                 EndpointsToDisableCount;
  UCXENDPOINT           *EndpointsToDisable;
} USBDEVICE_RESET, *PUSBDEVICE_RESET;