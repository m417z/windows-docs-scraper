typedef struct _IMAGEHLP_LINEW64 {
  DWORD   SizeOfStruct;
  PVOID   Key;
  DWORD   LineNumber;
  PWSTR   FileName;
  DWORD64 Address;
} IMAGEHLP_LINEW64, *PIMAGEHLP_LINEW64;