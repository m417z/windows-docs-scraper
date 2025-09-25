typedef struct _MEMORY_REGION {
  PUCHAR           VirtualBase;
  PHYSICAL_ADDRESS PhysicalBase;
  ULONG            Length;
} MEMORY_REGION, *PMEMORY_REGION;