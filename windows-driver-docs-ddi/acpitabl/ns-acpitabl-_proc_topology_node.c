typedef struct _PROC_TOPOLOGY_NODE {
  struct {
    UCHAR Type;
    UCHAR Length;
    UCHAR Reserved[2];
  };
  union {
    struct {
      PROC_TOPOLOGY_NODE_FLAGS Flags;
      ULONG                    Parent;
      ULONG                    ACPIProcessorId;
      ULONG                    NumberPrivateResources;
      ULONG                    PrivateResources[ANYSIZE_ARRAY];
    } HierarchyNode;
    struct {
      PROC_TOPOLOGY_CACHE_FLAGS      Flags;
      ULONG                          NextLevelCacheOffset;
      ULONG                          Size;
      ULONG                          Sets;
      UCHAR                          Associativity;
      PROC_TOPOLOGY_CACHE_ATTRIBUTES Attributes;
      USHORT                         LineSize;
      ULONG                          CacheId;
    } CacheNode;
    struct {
      ULONG   Vendor;
      ULONG64 Level1;
      ULONG64 Level2;
      USHORT  Major;
      USHORT  Minor;
      USHORT  Spin;
    } IdNode;
  };
} PROC_TOPOLOGY_NODE, *PPROC_TOPOLOGY_NODE;