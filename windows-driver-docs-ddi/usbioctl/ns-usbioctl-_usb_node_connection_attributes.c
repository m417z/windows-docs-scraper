typedef struct _USB_NODE_CONNECTION_ATTRIBUTES {
  ULONG                 ConnectionIndex;
  USB_CONNECTION_STATUS ConnectionStatus;
  ULONG                 PortAttributes;
} USB_NODE_CONNECTION_ATTRIBUTES, *PUSB_NODE_CONNECTION_ATTRIBUTES;