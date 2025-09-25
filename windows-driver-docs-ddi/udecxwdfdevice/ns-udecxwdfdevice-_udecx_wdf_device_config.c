typedef struct _UDECX_WDF_DEVICE_CONFIG {
  ULONG                                     Size;
  USHORT                                    NumberOfUsb20Ports;
  USHORT                                    NumberOfUsb30Ports;
  PFN_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY EvtUdecxWdfDeviceQueryUsbCapability;
  UDECX_WDF_DEVICE_RESET_ACTION             ResetAction;
  PFN_UDECX_WDF_DEVICE_RESET                EvtUdecxWdfDeviceReset;
} UDECX_WDF_DEVICE_CONFIG, *PUDECX_WDF_DEVICE_CONFIG;