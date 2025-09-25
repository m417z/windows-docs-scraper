typedef struct _NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS {
  NDIS_OBJECT_HEADER                       Header;
  ULONG                                    Flags;
  NDIS_SWITCH_PORT_ID                      PortId;
  NDIS_SWITCH_PORT_FEATURE_STATUS_TYPE     FeatureStatusType;
  NDIS_SWITCH_OBJECT_ID                    FeatureStatusId;
  NDIS_SWITCH_OBJECT_VERSION               FeatureStatusVersion;
  NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION SerializationVersion;
  NDIS_SWITCH_OBJECT_INSTANCE_ID           FeatureStatusInstanceId;
  ULONG                                    FeatureStatusBufferLength;
  ULONG                                    FeatureStatusBufferOffset;
  ULONG                                    Reserved;
} NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS, *PNDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS;