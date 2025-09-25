typedef struct _USB_30_HUB_DESCRIPTOR {
  UCHAR  bLength;
  UCHAR  bDescriptorType;
  UCHAR  bNumberOfPorts;
  USHORT wHubCharacteristics;
  UCHAR  bPowerOnToPowerGood;
  UCHAR  bHubControlCurrent;
  UCHAR  bHubHdrDecLat;
  USHORT wHubDelay;
  USHORT DeviceRemovable;
} USB_30_HUB_DESCRIPTOR, *PUSB_30_HUB_DESCRIPTOR;