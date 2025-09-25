typedef struct _NDIS_SWITCH_FEATURE_STATUS_PARAMETERS {
  NDIS_OBJECT_HEADER                       Header;
  ULONG                                    Flags;
  NDIS_SWITCH_FEATURE_STATUS_TYPE          FeatureStatusType;
  NDIS_SWITCH_OBJECT_ID                    FeatureStatusId;
  NDIS_SWITCH_OBJECT_INSTANCE_ID           FeatureStatusInstanceId;
  NDIS_SWITCH_OBJECT_VERSION               FeatureStatusVersion;
  NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION SerializationVersion;
  ULONG                                    FeatureStatusBufferOffset;
  ULONG                                    FeatureStatusBufferLength;
} NDIS_SWITCH_FEATURE_STATUS_PARAMETERS, *PNDIS_SWITCH_FEATURE_STATUS_PARAMETERS;