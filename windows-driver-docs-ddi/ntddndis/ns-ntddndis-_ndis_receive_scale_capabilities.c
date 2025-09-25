typedef struct _NDIS_RECEIVE_SCALE_CAPABILITIES {
  NDIS_OBJECT_HEADER  Header;
  NDIS_RSS_CAPS_FLAGS CapabilitiesFlags;
  ULONG               NumberOfInterruptMessages;
  ULONG               NumberOfReceiveQueues;
  USHORT              NumberOfIndirectionTableEntries;
} NDIS_RECEIVE_SCALE_CAPABILITIES, *PNDIS_RECEIVE_SCALE_CAPABILITIES;