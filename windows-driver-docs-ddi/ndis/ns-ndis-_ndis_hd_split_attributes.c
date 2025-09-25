typedef struct _NDIS_HD_SPLIT_ATTRIBUTES {
  NDIS_OBJECT_HEADER Header;
  ULONG              HardwareCapabilities;
  ULONG              CurrentCapabilities;
  ULONG              HDSplitFlags;
  ULONG              BackfillSize;
  ULONG              MaxHeaderSize;
} NDIS_HD_SPLIT_ATTRIBUTES, *PNDIS_HD_SPLIT_ATTRIBUTES;