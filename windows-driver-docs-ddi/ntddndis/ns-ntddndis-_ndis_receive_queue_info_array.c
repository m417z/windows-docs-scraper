typedef struct _NDIS_RECEIVE_QUEUE_INFO_ARRAY {
  NDIS_OBJECT_HEADER Header;
  ULONG              FirstElementOffset;
  ULONG              NumElements;
  ULONG              ElementSize;
} NDIS_RECEIVE_QUEUE_INFO_ARRAY, *PNDIS_RECEIVE_QUEUE_INFO_ARRAY;