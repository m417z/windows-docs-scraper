typedef struct _USB_DEVICE_QUALIFIER_DESCRIPTOR {
  UCHAR  bLength;
  UCHAR  bDescriptorType;
  USHORT bcdUSB;
  UCHAR  bDeviceClass;
  UCHAR  bDeviceSubClass;
  UCHAR  bDeviceProtocol;
  UCHAR  bMaxPacketSize0;
  UCHAR  bNumConfigurations;
  UCHAR  bReserved;
} USB_DEVICE_QUALIFIER_DESCRIPTOR, *PUSB_DEVICE_QUALIFIER_DESCRIPTOR;