typedef struct _NDIS_PCI_DEVICE_CUSTOM_PROPERTIES {
  NDIS_OBJECT_HEADER Header;
  UINT32             DeviceType;
  UINT32             CurrentSpeedAndMode;
  UINT32             CurrentPayloadSize;
  UINT32             MaxPayloadSize;
  UINT32             MaxReadRequestSize;
  UINT32             CurrentLinkSpeed;
  UINT32             CurrentLinkWidth;
  UINT32             MaxLinkSpeed;
  UINT32             MaxLinkWidth;
  UINT32             PciExpressVersion;
  UINT32             InterruptType;
  UINT32             MaxInterruptMessages;
} NDIS_PCI_DEVICE_CUSTOM_PROPERTIES, *PNDIS_PCI_DEVICE_CUSTOM_PROPERTIES;