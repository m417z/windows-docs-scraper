typedef struct _USBDEVICE_HUB_INFO {
  USBDEVICE_MGMT_HEADER Header;
  ULONG                 NumberOfPorts;
  ULONG                 NumberOfTTs;
  ULONG                 TTThinkTime;
} USBDEVICE_HUB_INFO, *PUSBDEVICE_HUB_INFO;