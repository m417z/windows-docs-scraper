typedef struct _NDIS_SWITCH_PROPERTY_ENUM_PARAMETERS {
  NDIS_OBJECT_HEADER                       Header;
  ULONG                                    Flags;
  NDIS_SWITCH_PROPERTY_TYPE                PropertyType;
  NDIS_SWITCH_OBJECT_ID                    PropertyId;
  NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION SerializationVersion;
  ULONG                                    FirstPropertyOffset;
  ULONG                                    NumProperties;
} NDIS_SWITCH_PROPERTY_ENUM_PARAMETERS, *PNDIS_SWITCH_PROPERTY_ENUM_PARAMETERS;