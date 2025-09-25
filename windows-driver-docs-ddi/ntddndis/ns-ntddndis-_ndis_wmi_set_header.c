typedef struct _NDIS_WMI_SET_HEADER {
  NDIS_OBJECT_HEADER Header;
  NDIS_PORT_NUMBER   PortNumber;
  NET_LUID           NetLuid;
  ULONG64            RequestId;
  ULONG              Timeout;
  UCHAR              Padding[4];
} NDIS_WMI_SET_HEADER, *PNDIS_WMI_SET_HEADER;