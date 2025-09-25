LONG DrvQueryTrueTypeTable(
  ULONG_PTR iFile,
  ULONG     ulFont,
  ULONG     ulTag,
  PTRDIFF   dpStart,
  ULONG     cjBuf,
  BYTE      *pjBuf,
  PBYTE     *ppjTable,
  ULONG     *pcjTable
);