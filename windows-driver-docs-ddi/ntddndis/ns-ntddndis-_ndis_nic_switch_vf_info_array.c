typedef struct _NDIS_NIC_SWITCH_VF_INFO_ARRAY {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  NDIS_NIC_SWITCH_ID SwitchId;
  ULONG              FirstElementOffset;
  ULONG              NumElements;
  ULONG              ElementSize;
} NDIS_NIC_SWITCH_VF_INFO_ARRAY, *PNDIS_NIC_SWITCH_VF_INFO_ARRAY;