typedef struct _NDIS_SWITCH_PORT_ARRAY {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  USHORT             FirstElementOffset;
  ULONG              NumElements;
  ULONG              ElementSize;
} NDIS_SWITCH_PORT_ARRAY, *PNDIS_SWITCH_PORT_ARRAY;