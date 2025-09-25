typedef struct _USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION {
  ULONG                                      ConnectionIndex;
  ULONG                                      Length;
  USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED RxSuperSpeedPlus;
  ULONG                                      RxLaneCount;
  USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED TxSuperSpeedPlus;
  ULONG                                      TxLaneCount;
} USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION, *PUSB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION;