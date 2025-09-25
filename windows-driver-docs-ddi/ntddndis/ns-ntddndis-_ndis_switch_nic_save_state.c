typedef struct _NDIS_SWITCH_NIC_SAVE_STATE {
  NDIS_OBJECT_HEADER                 Header;
  ULONG                              Flags;
  NDIS_SWITCH_PORT_ID                PortId;
  NDIS_SWITCH_NIC_INDEX              NicIndex;
  GUID                               ExtensionId;
  NDIS_SWITCH_EXTENSION_FRIENDLYNAME ExtensionFriendlyName;
  GUID                               FeatureClassId;
  USHORT                             SaveDataSize;
  USHORT                             SaveDataOffset;
  ULONG                              SaveDataSizeOverflow;
} NDIS_SWITCH_NIC_SAVE_STATE, *PNDIS_SWITCH_NIC_SAVE_STATE;