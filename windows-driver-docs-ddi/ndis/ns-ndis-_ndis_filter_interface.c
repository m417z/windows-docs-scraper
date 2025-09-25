typedef struct _NDIS_FILTER_INTERFACE {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              FilterType;
  ULONG              FilterRunType;
  NET_IFINDEX        IfIndex;
  NET_LUID           NetLuid;
  NDIS_STRING        FilterClass;
  NDIS_STRING        FilterInstanceName;
} NDIS_FILTER_INTERFACE, *PNDIS_FILTER_INTERFACE;