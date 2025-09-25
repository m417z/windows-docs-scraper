typedef struct _NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO {
  NDIS_OBJECT_HEADER             Header;
  ULONG                          Flags;
  NDIS_SWITCH_OBJECT_VERSION     PropertyVersion;
  NDIS_SWITCH_OBJECT_INSTANCE_ID PropertyInstanceId;
  ULONG                          QwordAlignedPropertyBufferLength;
  ULONG                          PropertyBufferLength;
  ULONG                          PropertyBufferOffset;
} NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO, *PNDIS_SWITCH_PORT_PROPERTY_ENUM_INFO;