typedef struct _USB_ENDPOINT_DESCRIPTOR {
  UCHAR  bLength;
  UCHAR  bDescriptorType;
  UCHAR  bEndpointAddress;
  UCHAR  bmAttributes;
  USHORT wMaxPacketSize;
  UCHAR  bInterval;
} USB_ENDPOINT_DESCRIPTOR, *PUSB_ENDPOINT_DESCRIPTOR;