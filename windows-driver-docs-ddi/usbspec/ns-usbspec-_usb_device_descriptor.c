typedef struct _USB_DEVICE_DESCRIPTOR {
  UCHAR  bLength;
  UCHAR  bDescriptorType;
  USHORT bcdUSB;
  UCHAR  bDeviceClass;
  UCHAR  bDeviceSubClass;
  UCHAR  bDeviceProtocol;
  UCHAR  bMaxPacketSize0;
  USHORT idVendor;
  USHORT idProduct;
  USHORT bcdDevice;
  UCHAR  iManufacturer;
  UCHAR  iProduct;
  UCHAR  iSerialNumber;
  UCHAR  bNumConfigurations;
} USB_DEVICE_DESCRIPTOR, *PUSB_DEVICE_DESCRIPTOR;