typedef struct _IMAGEHLP_SYMBOL64 {
  DWORD   SizeOfStruct;
  DWORD64 Address;
  DWORD   Size;
  DWORD   Flags;
  DWORD   MaxNameLength;
  CHAR    Name[1];
} IMAGEHLP_SYMBOL64, *PIMAGEHLP_SYMBOL64;