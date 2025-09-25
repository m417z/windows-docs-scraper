typedef struct _USB_TOPOLOGY_ADDRESS {
  ULONG  PciBusNumber;
  ULONG  PciDeviceNumber;
  ULONG  PciFunctionNumber;
  ULONG  Reserved;
  USHORT RootHubPortNumber;
  USHORT HubPortNumber[5];
  USHORT Reserved2;
} USB_TOPOLOGY_ADDRESS, *PUSB_TOPOLOGY_ADDRESS;