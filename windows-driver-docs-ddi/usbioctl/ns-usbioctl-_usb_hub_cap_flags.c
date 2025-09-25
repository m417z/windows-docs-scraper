typedef union _USB_HUB_CAP_FLAGS {
  ULONG  ul;
  struct {
    ULONG HubIsHighSpeedCapable : 1;
    ULONG HubIsHighSpeed : 1;
    ULONG HubIsMultiTtCapable : 1;
    ULONG HubIsMultiTt : 1;
    ULONG HubIsRoot : 1;
    ULONG HubIsArmedWakeOnConnect : 1;
    ULONG HubIsBusPowered : 1;
    ULONG ReservedMBZ : 25;
  };
} USB_HUB_CAP_FLAGS, *PUSB_HUB_CAP_FLAGS;