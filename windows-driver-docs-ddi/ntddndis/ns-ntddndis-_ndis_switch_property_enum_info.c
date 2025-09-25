typedef struct _NDIS_SWITCH_PROPERTY_ENUM_INFO {
  NDIS_OBJECT_HEADER             Header;
  ULONG                          Flags;
  NDIS_SWITCH_OBJECT_INSTANCE_ID PropertyInstanceId;
  NDIS_SWITCH_OBJECT_VERSION     PropertyVersion;
  ULONG                          QwordAlignedPropertyBufferLength;
  ULONG                          PropertyBufferLength;
  ULONG                          PropertyBufferOffset;
} NDIS_SWITCH_PROPERTY_ENUM_INFO, *PNDIS_SWITCH_PROPERTY_ENUM_INFO;