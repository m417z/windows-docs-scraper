typedef struct _USB_NODE_CONNECTION_INFORMATION_EX_V2 {
  ULONG                                       ConnectionIndex;
  ULONG                                       Length;
  USB_PROTOCOLS                               SupportedUsbProtocols;
  USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS Flags;
} USB_NODE_CONNECTION_INFORMATION_EX_V2, *PUSB_NODE_CONNECTION_INFORMATION_EX_V2;