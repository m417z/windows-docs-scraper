typedef struct _IMAGEHLP_LINE {
  DWORD SizeOfStruct;
  PVOID Key;
  DWORD LineNumber;
  PCHAR FileName;
  DWORD Address;
} IMAGEHLP_LINE, *PIMAGEHLP_LINE;