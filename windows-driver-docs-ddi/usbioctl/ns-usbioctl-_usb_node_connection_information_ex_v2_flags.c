typedef union _USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS {
  ULONG  ul;
  struct {
    ULONG DeviceIsOperatingAtSuperSpeedOrHigher : 1;
    ULONG DeviceIsSuperSpeedCapableOrHigher : 1;
    ULONG DeviceIsOperatingAtSuperSpeedPlusOrHigher : 1;
    ULONG DeviceIsSuperSpeedPlusCapableOrHigher : 1;
    ULONG ReservedMBZ : 28;
  };
} USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS, *PUSB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS;