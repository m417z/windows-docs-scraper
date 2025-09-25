typedef struct _NDIS_SWITCH_NIC_ARRAY {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  USHORT             FirstElementOffset;
  ULONG              NumElements;
  ULONG              ElementSize;
} NDIS_SWITCH_NIC_ARRAY, *PNDIS_SWITCH_NIC_ARRAY;