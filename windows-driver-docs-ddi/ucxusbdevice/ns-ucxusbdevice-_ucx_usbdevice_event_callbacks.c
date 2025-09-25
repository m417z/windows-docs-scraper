typedef struct _UCX_USBDEVICE_EVENT_CALLBACKS {
  ULONG                                  Size;
  PFN_UCX_USBDEVICE_ENDPOINTS_CONFIGURE  EvtUsbDeviceEndpointsConfigure;
  PFN_UCX_USBDEVICE_ENABLE               EvtUsbDeviceEnable;
  PFN_UCX_USBDEVICE_DISABLE              EvtUsbDeviceDisable;
  PFN_UCX_USBDEVICE_RESET                EvtUsbDeviceReset;
  PFN_UCX_USBDEVICE_ADDRESS              EvtUsbDeviceAddress;
  PFN_UCX_USBDEVICE_UPDATE               EvtUsbDeviceUpdate;
  PFN_UCX_USBDEVICE_HUB_INFO             EvtUsbDeviceHubInfo;
  PFN_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD EvtUsbDeviceDefaultEndpointAdd;
  PFN_UCX_USBDEVICE_ENDPOINT_ADD         EvtUsbDeviceEndpointAdd;
  PFN_UCX_USBDEVICE_SUSPEND              EvtUsbDeviceSuspend;
  PFN_UCX_USBDEVICE_RESUME               EvtUsbDeviceResume;
  PFN_UCX_USBDEVICE_GET_CHARACTERISTIC   EvtUsbDeviceGetCharacteristic;
} UCX_USBDEVICE_EVENT_CALLBACKS, *PUCX_USBDEVICE_EVENT_CALLBACKS;