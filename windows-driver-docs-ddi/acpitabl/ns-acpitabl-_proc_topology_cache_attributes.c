typedef union _PROC_TOPOLOGY_CACHE_ATTRIBUTES {
  struct {
    UCHAR ReadAllocate : 1;
    UCHAR WriteAllocate : 1;
    UCHAR CacheType : 2;
    UCHAR WritePolicy : 1;
    UCHAR Reserved : 3;
  };
  UCHAR  AsUCHAR;
} PROC_TOPOLOGY_CACHE_ATTRIBUTES, *PPROC_TOPOLOGY_CACHE_ATTRIBUTES;