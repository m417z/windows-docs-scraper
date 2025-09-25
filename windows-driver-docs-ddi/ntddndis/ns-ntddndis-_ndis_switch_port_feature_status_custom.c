typedef struct _NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              FeatureStatusBufferLength;
  ULONG              FeatureStatusBufferOffset;
} NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM, *PNDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM;