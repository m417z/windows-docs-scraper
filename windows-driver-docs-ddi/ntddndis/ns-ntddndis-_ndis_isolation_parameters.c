typedef struct _NDIS_ISOLATION_PARAMETERS {
  NDIS_OBJECT_HEADER  Header;
  ULONG               Flags;
  NDIS_ISOLATION_MODE IsolationMode;
  BOOLEAN             AllowUntaggedTraffic;
  ULONG               NumRoutingDomainEntries;
  ULONG               FirstRoutingDomainEntryOffset;
} NDIS_ISOLATION_PARAMETERS, *PNDIS_ISOLATION_PARAMETERS;