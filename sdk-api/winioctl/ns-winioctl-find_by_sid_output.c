typedef struct {
  DWORD NextEntryOffset;
  DWORD FileIndex;
  DWORD FileNameLength;
  WCHAR FileName[1];
} FIND_BY_SID_OUTPUT, *PFIND_BY_SID_OUTPUT;