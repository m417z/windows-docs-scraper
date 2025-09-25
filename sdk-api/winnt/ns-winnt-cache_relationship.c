typedef struct _CACHE_RELATIONSHIP {
  BYTE                 Level;
  BYTE                 Associativity;
  WORD                 LineSize;
  DWORD                CacheSize;
  PROCESSOR_CACHE_TYPE Type;
  BYTE                 Reserved[18];
  WORD                 GroupCount;
  union {
    GROUP_AFFINITY GroupMask;
    GROUP_AFFINITY GroupMasks[ANYSIZE_ARRAY];
  } DUMMYUNIONNAME;
} CACHE_RELATIONSHIP, *PCACHE_RELATIONSHIP;