typedef struct _USB_PORT_CONNECTOR_PROPERTIES {
  ULONG               ConnectionIndex;
  ULONG               ActualLength;
  USB_PORT_PROPERTIES UsbPortProperties;
  USHORT              CompanionIndex;
  USHORT              CompanionPortNumber;
  WCHAR               CompanionHubSymbolicLinkName[1];
} USB_PORT_CONNECTOR_PROPERTIES, *PUSB_PORT_CONNECTOR_PROPERTIES;