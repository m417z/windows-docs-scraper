typedef struct _USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR {
  UCHAR  bLength;
  UCHAR  bDescriptorType;
  UCHAR  bMaxBurst;
  union {
    UCHAR AsUchar;
    struct {
      UCHAR MaxStreams : 5;
      UCHAR Reserved1 : 3;
    } Bulk;
    struct {
      UCHAR Mult : 2;
      UCHAR Reserved2 : 5;
      UCHAR SspCompanion : 1;
    } Isochronous;
  } bmAttributes;
  USHORT wBytesPerInterval;
} USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR, *PUSB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR;