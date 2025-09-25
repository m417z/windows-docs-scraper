typedef struct _UDECX_USB_DEVICE_STATE_CHANGE_CALLBACKS {
  ULONG                                              Size;
  PFN_UDECX_USB_DEVICE_D0_ENTRY                      EvtUsbDeviceLinkPowerEntry;
  PFN_UDECX_USB_DEVICE_D0_EXIT                       EvtUsbDeviceLinkPowerExit;
  PFN_UDECX_USB_DEVICE_SET_FUNCTION_SUSPEND_AND_WAKE EvtUsbDeviceSetFunctionSuspendAndWake;
  PFN_UDECX_USB_DEVICE_POST_ENUMERATION_RESET        EvtUsbDeviceReset;
  PFN_UDECX_USB_DEVICE_DEFAULT_ENDPOINT_ADD          EvtUsbDeviceDefaultEndpointAdd;
  PFN_UDECX_USB_DEVICE_ENDPOINT_ADD                  EvtUsbDeviceEndpointAdd;
  PFN_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE           EvtUsbDeviceEndpointsConfigure;
} UDECX_USB_DEVICE_STATE_CHANGE_CALLBACKS, *PUDECX_USB_DEVICE_STATE_CHANGE_CALLBACKS;