typedef struct _NDIS_SWITCH_PORT_PROPERTY_ISOLATION {
  NDIS_OBJECT_HEADER  Header;
  ULONG               Flags;
  NDIS_ISOLATION_MODE IsolationMode;
  BOOLEAN             AllowUntaggedTraffic;
  UINT32              DefaultIsolationId;
} NDIS_SWITCH_PORT_PROPERTY_ISOLATION, *PNDIS_SWITCH_PORT_PROPERTY_ISOLATION;