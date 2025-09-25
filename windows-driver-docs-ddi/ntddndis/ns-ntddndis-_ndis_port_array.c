typedef struct _NDIS_PORT_ARRAY {
  NDIS_OBJECT_HEADER        Header;
  ULONG                     NumberOfPorts;
  ULONG                     OffsetFirstPort;
  ULONG                     ElementSize;
  NDIS_PORT_CHARACTERISTICS Ports[1];
} NDIS_PORT_ARRAY, *PNDIS_PORT_ARRAY;