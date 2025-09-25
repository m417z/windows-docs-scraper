typedef struct _MEM_ADDRESS_REQUIREMENTS {
  PVOID  LowestStartingAddress;
  PVOID  HighestEndingAddress;
  SIZE_T Alignment;
} MEM_ADDRESS_REQUIREMENTS, *PMEM_ADDRESS_REQUIREMENTS;