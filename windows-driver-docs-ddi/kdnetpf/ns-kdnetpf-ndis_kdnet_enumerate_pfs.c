typedef struct _NDIS_KDNET_ENUMERATE_PFS {
  NDIS_OBJECT_HEADER Header;
  ULONG              ElementSize;
  ULONG              NumberOfElements;
  ULONG              OffsetToFirstElement;
} NDIS_KDNET_ENUMERATE_PFS, *PNDIS_KDNET_ENUMERATE_PFS;