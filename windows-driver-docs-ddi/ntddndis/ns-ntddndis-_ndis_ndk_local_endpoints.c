typedef struct _NDIS_NDK_LOCAL_ENDPOINTS {
  NDIS_OBJECT_HEADER            Header;
  ULONG                         Flags;
  ULONG                         Count;
  BOOLEAN                       NDLocalEndpointsMappedtoTCPLocalEndpoints;
  NDIS_NDK_LOCAL_ENDPOINT_ENTRY LocalEndpoints[1];
} NDIS_NDK_LOCAL_ENDPOINTS;