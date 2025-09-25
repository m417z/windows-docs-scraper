typedef struct _NDIS_WMI_ENUM_ADAPTER {
  NDIS_OBJECT_HEADER Header;
  NET_IFINDEX        IfIndex;
  NET_LUID           NetLuid;
  USHORT             DeviceNameLength;
  CHAR               DeviceName[1];
} NDIS_WMI_ENUM_ADAPTER, *PNDIS_WMI_ENUM_ADAPTER;