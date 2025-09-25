typedef struct _USB_DESCRIPTOR_REQUEST {
  ULONG  ConnectionIndex;
  struct {
    UCHAR  bmRequest;
    UCHAR  bRequest;
    USHORT wValue;
    USHORT wIndex;
    USHORT wLength;
  } SetupPacket;
  UCHAR  Data[0];
} USB_DESCRIPTOR_REQUEST, *PUSB_DESCRIPTOR_REQUEST;