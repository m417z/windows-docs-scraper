typedef struct {
  PHYSICAL_ADDRESS Start;
  PHYSICAL_ADDRESS MaxEnd;
  PVOID            VirtualAddress;
  ULONG            Length;
  BOOLEAN          Cached;
  BOOLEAN          Aligned;
} DEBUG_MEMORY_REQUIREMENTS, *PDEBUG_MEMORY_REQUIREMENTS;