typedef struct _NDIS_PM_CAPABILITIES {
  NDIS_OBJECT_HEADER      Header;
  ULONG                   Flags;
  ULONG                   SupportedWoLPacketPatterns;
  ULONG                   NumTotalWoLPatterns;
  ULONG                   MaxWoLPatternSize;
  ULONG                   MaxWoLPatternOffset;
  ULONG                   MaxWoLPacketSaveBuffer;
  ULONG                   SupportedProtocolOffloads;
  ULONG                   NumArpOffloadIPv4Addresses;
  ULONG                   NumNSOffloadIPv6Addresses;
  NDIS_DEVICE_POWER_STATE MinMagicPacketWakeUp;
  NDIS_DEVICE_POWER_STATE MinPatternWakeUp;
  NDIS_DEVICE_POWER_STATE MinLinkChangeWakeUp;
  ULONG                   SupportedWakeUpEvents;
  ULONG                   MediaSpecificWakeUpEvents;
} NDIS_PM_CAPABILITIES, *PNDIS_PM_CAPABILITIES;