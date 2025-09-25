VOID UCX_USBDEVICE_EVENT_CALLBACKS_INIT(
  [out] PUCX_USBDEVICE_EVENT_CALLBACKS         Callbacks,
  [in]  PFN_UCX_USBDEVICE_ENDPOINTS_CONFIGURE  EvtUsbDeviceEndpointsConfigure,
  [in]  PFN_UCX_USBDEVICE_ENABLE               EvtUsbDeviceEnable,
  [in]  PFN_UCX_USBDEVICE_DISABLE              EvtUsbDeviceDisable,
  [in]  PFN_UCX_USBDEVICE_RESET                EvtUsbDeviceReset,
  [in]  PFN_UCX_USBDEVICE_ADDRESS              EvtUsbDeviceAddress,
  [in]  PFN_UCX_USBDEVICE_UPDATE               EvtUsbDeviceUpdate,
  [in]  PFN_UCX_USBDEVICE_HUB_INFO             EvtUsbDeviceHubInfo,
  [in]  PFN_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD EvtUsbDeviceDefaultEndpointAdd,
  [in]  PFN_UCX_USBDEVICE_ENDPOINT_ADD         EvtUsbDeviceEndpointAdd
);