typedef struct _UFX_DEVICE_CALLBACKS {
  ULONG                                           Size;
  PFN_UFX_DEVICE_HOST_CONNECT                     EvtDeviceHostConnect;
  PFN_UFX_DEVICE_HOST_DISCONNECT                  EvtDeviceHostDisconnect;
  PFN_UFX_DEVICE_ADDRESSED                        EvtDeviceAddressed;
  PFN_UFX_DEVICE_ENDPOINT_ADD                     EvtDeviceEndpointAdd;
  PFN_UFX_DEVICE_DEFAULT_ENDPOINT_ADD             EvtDeviceDefaultEndpointAdd;
  PFN_UFX_DEVICE_USB_STATE_CHANGE                 EvtDeviceUsbStateChange;
  PFN_UFX_DEVICE_PORT_CHANGE                      EvtDevicePortChange;
  PFN_UFX_DEVICE_PORT_DETECT                      EvtDevicePortDetect;
  PFN_UFX_DEVICE_REMOTE_WAKEUP_SIGNAL             EvtDeviceRemoteWakeupSignal;
  PFN_UFX_DEVICE_CONTROLLER_RESET                 EvtDeviceControllerReset;
  PFN_UFX_DEVICE_TEST_MODE_SET                    EvtDeviceTestModeSet;
  PFN_UFX_DEVICE_TESTHOOK                         EvtDeviceTestHook;
  PFN_UFX_DEVICE_SUPER_SPEED_POWER_FEATURE        EvtDeviceSuperSpeedPowerFeature;
  PFN_UFX_DEVICE_PROPRIETARY_CHARGER_DETECT       EvtDeviceProprietaryChargerDetect;
  PFN_UFX_DEVICE_PROPRIETARY_CHARGER_SET_PROPERTY EvtDeviceProprietaryChargerSetProperty;
  PFN_UFX_DEVICE_PROPRIETARY_CHARGER_RESET        EvtDeviceProprietaryChargerReset;
} UFX_DEVICE_CALLBACKS, *PUFX_DEVICE_CALLBACKS;