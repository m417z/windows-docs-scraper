typedef struct Mem_Range_s {
  DWORDLONG MR_Align;
  ULONG     MR_nBytes;
  DWORDLONG MR_Min;
  DWORDLONG MR_Max;
  DWORD     MR_Flags;
  DWORD     MR_Reserved;
} MEM_RANGE, *PMEM_RANGE;