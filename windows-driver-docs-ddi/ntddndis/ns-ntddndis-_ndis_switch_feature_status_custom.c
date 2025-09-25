typedef struct _NDIS_SWITCH_FEATURE_STATUS_CUSTOM {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              FeatureStatusCustomBufferLength;
  ULONG              FeatureStatusCustomBufferOffset;
} NDIS_SWITCH_FEATURE_STATUS_CUSTOM, *PNDIS_SWITCH_FEATURE_STATUS_CUSTOM;