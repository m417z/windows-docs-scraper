typedef struct _CACHE_DESCRIPTOR {
  BYTE                 Level;
  BYTE                 Associativity;
  WORD                 LineSize;
  DWORD                Size;
  PROCESSOR_CACHE_TYPE Type;
} CACHE_DESCRIPTOR, *PCACHE_DESCRIPTOR;