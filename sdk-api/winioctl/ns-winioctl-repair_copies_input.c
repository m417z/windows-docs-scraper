typedef struct _REPAIR_COPIES_INPUT {
  DWORD         Size;
  DWORD         Flags;
  LARGE_INTEGER FileOffset;
  DWORD         Length;
  DWORD         SourceCopy;
  DWORD         NumberOfRepairCopies;
  DWORD         RepairCopies[ANYSIZE_ARRAY];
} REPAIR_COPIES_INPUT, *PREPAIR_COPIES_INPUT;