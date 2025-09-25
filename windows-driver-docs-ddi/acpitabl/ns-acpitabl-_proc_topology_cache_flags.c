typedef union _PROC_TOPOLOGY_CACHE_FLAGS {
  struct {
    ULONG SizeValid : 1;
    ULONG SetsValid : 1;
    ULONG AssociativityValid : 1;
    ULONG AllocationTypeValid : 1;
    ULONG CacheTypeValid : 1;
    ULONG WritePolicyValid : 1;
    ULONG LineSizeValid : 1;
    ULONG CacheIdValid : 1;
    ULONG Reserved : 24;
  };
  ULONG  AsULONG;
} PROC_TOPOLOGY_CACHE_FLAGS, *PPROC_TOPOLOGY_CACHE_FLAGS;