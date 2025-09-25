typedef struct _NDIS_ROUTING_DOMAIN_ENTRY {
  NDIS_OBJECT_HEADER       Header;
  ULONG                    Flags;
  NDIS_ROUTING_DOMAIN_ID   RoutingDomainId;
  NDIS_ROUTING_DOMAIN_NAME RoutingDomainName;
  ULONG                    NumIsolationEntries;
  ULONG                    FirstIsolationEntryOffset;
} NDIS_ROUTING_DOMAIN_ENTRY, *PNDIS_ROUTING_DOMAIN_ENTRY;