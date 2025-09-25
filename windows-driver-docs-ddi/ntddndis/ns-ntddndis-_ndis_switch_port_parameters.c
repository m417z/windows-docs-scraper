typedef struct _NDIS_SWITCH_PORT_PARAMETERS {
  NDIS_OBJECT_HEADER            Header;
  ULONG                         Flags;
  NDIS_SWITCH_PORT_ID           PortId;
  NDIS_SWITCH_PORT_NAME         PortName;
  NDIS_SWITCH_PORT_FRIENDLYNAME PortFriendlyName;
  NDIS_SWITCH_PORT_TYPE         PortType;
  BOOLEAN                       IsValidationPort;
  NDIS_SWITCH_PORT_STATE        PortState;
} NDIS_SWITCH_PORT_PARAMETERS, *PNDIS_SWITCH_PORT_PARAMETERS;