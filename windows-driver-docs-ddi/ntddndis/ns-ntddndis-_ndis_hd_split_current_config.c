typedef struct _NDIS_HD_SPLIT_CURRENT_CONFIG {
  NDIS_OBJECT_HEADER Header;
  ULONG              HardwareCapabilities;
  ULONG              CurrentCapabilities;
  ULONG              HDSplitFlags;
  ULONG              HDSplitCombineFlags;
  ULONG              BackfillSize;
  ULONG              MaxHeaderSize;
} NDIS_HD_SPLIT_CURRENT_CONFIG, *PNDIS_HD_SPLIT_CURRENT_CONFIG;