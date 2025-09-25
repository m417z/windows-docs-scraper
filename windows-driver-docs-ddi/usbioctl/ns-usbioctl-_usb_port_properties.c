typedef union _USB_PORT_PROPERTIES {
  ULONG  ul;
  struct {
    ULONG PortIsUserConnectable : 1;
    ULONG PortIsDebugCapable : 1;
    ULONG PortHasMultipleCompanions : 1;
    ULONG PortConnectorIsTypeC : 1;
    ULONG ReservedMBZ : 28;
  };
} USB_PORT_PROPERTIES, *PUSB_PORT_PROPERTIES;