typedef union _USB_PROTOCOLS {
  ULONG  ul;
  struct {
    ULONG Usb110 : 1;
    ULONG Usb200 : 1;
    ULONG Usb300 : 1;
    ULONG ReservedMBZ : 29;
  };
} USB_PROTOCOLS, *PUSB_PROTOCOLS;