typedef struct Mem_Resource_s {
  MEM_DES   MEM_Header;
  MEM_RANGE MEM_Data[ANYSIZE_ARRAY];
} MEM_RESOURCE, *PMEM_RESOURCE;