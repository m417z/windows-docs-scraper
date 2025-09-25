typedef struct _IMAGEHLP_LINE64 {
  DWORD   SizeOfStruct;
  PVOID   Key;
  DWORD   LineNumber;
  PCHAR   FileName;
  DWORD64 Address;
} IMAGEHLP_LINE64, *PIMAGEHLP_LINE64;