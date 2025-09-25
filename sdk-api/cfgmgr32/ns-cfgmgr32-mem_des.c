typedef struct Mem_Des_s {
  DWORD     MD_Count;
  DWORD     MD_Type;
  DWORDLONG MD_Alloc_Base;
  DWORDLONG MD_Alloc_End;
  DWORD     MD_Flags;
  DWORD     MD_Reserved;
} MEM_DES, *PMEM_DES;