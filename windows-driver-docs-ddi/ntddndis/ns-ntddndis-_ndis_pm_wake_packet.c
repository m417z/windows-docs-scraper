typedef struct _NDIS_PM_WAKE_PACKET {
  NDIS_OBJECT_HEADER     Header;
  ULONG                  Flags;
  ULONG                  PatternId;
  NDIS_PM_COUNTED_STRING PatternFriendlyName;
  ULONG                  OriginalPacketSize;
  ULONG                  SavedPacketSize;
  ULONG                  SavedPacketOffset;
} NDIS_PM_WAKE_PACKET, *PNDIS_PM_WAKE_PACKET;