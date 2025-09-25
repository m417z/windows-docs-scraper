typedef struct _NDIS_WMI_METHOD_HEADER {
  NDIS_OBJECT_HEADER Header;
  NDIS_PORT_NUMBER   PortNumber;
  NET_LUID           NetLuid;
  ULONG64            RequestId;
  ULONG              Timeout;
  UCHAR              Padding[4];
} NDIS_WMI_METHOD_HEADER, *PNDIS_WMI_METHOD_HEADER;