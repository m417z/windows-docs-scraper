typedef struct {
  ULONG NextEntryOffset;
  ULONG FileIndex;
  ULONG FileNameLength;
  WCHAR FileName[1];
} FIND_BY_SID_OUTPUT, *PFIND_BY_SID_OUTPUT;