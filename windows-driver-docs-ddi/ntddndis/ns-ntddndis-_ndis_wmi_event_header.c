typedef struct _NDIS_WMI_EVENT_HEADER {
  NDIS_OBJECT_HEADER Header;
  NET_IFINDEX        IfIndex;
  NET_LUID           NetLuid;
  ULONG64            RequestId;
  NDIS_PORT_NUMBER   PortNumber;
  ULONG              DeviceNameLength;
  ULONG              DeviceNameOffset;
  UCHAR              Padding[4];
} NDIS_WMI_EVENT_HEADER, *PNDIS_WMI_EVENT_HEADER;