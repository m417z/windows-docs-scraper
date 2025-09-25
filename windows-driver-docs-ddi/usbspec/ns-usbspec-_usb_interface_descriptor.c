typedef struct _USB_INTERFACE_DESCRIPTOR {
  UCHAR bLength;
  UCHAR bDescriptorType;
  UCHAR bInterfaceNumber;
  UCHAR bAlternateSetting;
  UCHAR bNumEndpoints;
  UCHAR bInterfaceClass;
  UCHAR bInterfaceSubClass;
  UCHAR bInterfaceProtocol;
  UCHAR iInterface;
} USB_INTERFACE_DESCRIPTOR, *PUSB_INTERFACE_DESCRIPTOR;