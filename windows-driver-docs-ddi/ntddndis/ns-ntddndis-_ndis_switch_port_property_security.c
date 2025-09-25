typedef struct _NDIS_SWITCH_PORT_PROPERTY_SECURITY {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  BOOLEAN            AllowMacSpoofing;
  BOOLEAN            AllowIeeePriorityTag;
  UINT32             VirtualSubnetId;
  BOOLEAN            AllowTeaming;
  UINT32             DynamicIPAddressLimit;
} NDIS_SWITCH_PORT_PROPERTY_SECURITY, *PNDIS_SWITCH_PORT_PROPERTY_SECURITY;