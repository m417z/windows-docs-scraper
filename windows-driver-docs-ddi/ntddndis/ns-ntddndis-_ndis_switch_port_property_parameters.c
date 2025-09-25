typedef struct _NDIS_SWITCH_PORT_PROPERTY_PARAMETERS {
  NDIS_OBJECT_HEADER                       Header;
  ULONG                                    Flags;
  NDIS_SWITCH_PORT_ID                      PortId;
  NDIS_SWITCH_PORT_PROPERTY_TYPE           PropertyType;
  NDIS_SWITCH_OBJECT_ID                    PropertyId;
  NDIS_SWITCH_OBJECT_VERSION               PropertyVersion;
  NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION SerializationVersion;
  NDIS_SWITCH_OBJECT_INSTANCE_ID           PropertyInstanceId;
  ULONG                                    PropertyBufferLength;
  ULONG                                    PropertyBufferOffset;
  ULONG                                    Reserved;
} NDIS_SWITCH_PORT_PROPERTY_PARAMETERS, *PNDIS_SWITCH_PORT_PROPERTY_PARAMETERS;