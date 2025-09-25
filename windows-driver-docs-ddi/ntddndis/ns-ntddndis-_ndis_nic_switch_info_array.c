typedef struct _NDIS_NIC_SWITCH_INFO_ARRAY {
  NDIS_OBJECT_HEADER Header;
  ULONG              FirstElementOffset;
  ULONG              NumElements;
  ULONG              ElementSize;
} NDIS_NIC_SWITCH_INFO_ARRAY, *PNDIS_NIC_SWITCH_INFO_ARRAY;