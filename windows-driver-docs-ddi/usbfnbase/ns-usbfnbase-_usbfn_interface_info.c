typedef struct _USBFN_INTERFACE_INFO {
  UINT8           InterfaceNumber;
  USBFN_BUS_SPEED Speed;
  USHORT          Size;
  UCHAR           InterfaceDescriptorSet[1];
} USBFN_INTERFACE_INFO, *PUSBFN_INTERFACE_INFO;