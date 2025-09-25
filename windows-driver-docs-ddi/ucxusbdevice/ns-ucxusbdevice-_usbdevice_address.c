typedef struct _USBDEVICE_ADDRESS {
  USBDEVICE_MGMT_HEADER Header;
  ULONG                 Reserved;
  ULONG                 Address;
} USBDEVICE_ADDRESS, *PUSBDEVICE_ADDRESS;