typedef struct _NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN {
  NDIS_OBJECT_HEADER       Header;
  ULONG                    Flags;
  NDIS_ROUTING_DOMAIN_ID   RoutingDomainId;
  NDIS_ROUTING_DOMAIN_NAME RoutingDomainName;
  ULONG                    NumIsolationEntries;
  USHORT                   FirstIsolationEntryOffset;
} NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN, *PNDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN;