typedef struct _QUERY_FILE_LAYOUT_INPUT {
  union {
    ULONG FilterEntryCount;
    ULONG NumberOfPairs;
  } DUMMYUNIONNAME;
  ULONG                         Flags;
  QUERY_FILE_LAYOUT_FILTER_TYPE FilterType;
  ULONG                         Reserved;
  union {
    CLUSTER_RANGE        ClusterRanges[1];
    FILE_REFERENCE_RANGE FileReferenceRanges[1];
    STORAGE_RESERVE_ID   StorageReserveIds[1];
  } Filter;
} QUERY_FILE_LAYOUT_INPUT, *PQUERY_FILE_LAYOUT_INPUT;