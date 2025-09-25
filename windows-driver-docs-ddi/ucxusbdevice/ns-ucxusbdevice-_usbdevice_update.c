typedef struct _USBDEVICE_UPDATE {
  USBDEVICE_MGMT_HEADER                       Header;
  USBDEVICE_UPDATE_FLAGS                      Flags;
  PUSB_DEVICE_DESCRIPTOR                      DeviceDescriptor;
  PUSB_BOS_DESCRIPTOR                         BosDescriptor;
  ULONG                                       MaxExitLatency;
  BOOLEAN                                     IsHub;
  USBDEVICE_UPDATE_FAILURE_FLAGS              FailureFlags;
  USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS Usb20HardwareLpmParameters;
  USHORT                                      RootPortResumeTime;
  BOOLEAN                                     Reserved;
} USBDEVICE_UPDATE, *PUSBDEVICE_UPDATE;