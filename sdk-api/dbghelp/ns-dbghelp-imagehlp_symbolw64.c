typedef struct _IMAGEHLP_SYMBOLW64 {
  DWORD   SizeOfStruct;
  DWORD64 Address;
  DWORD   Size;
  DWORD   Flags;
  DWORD   MaxNameLength;
  WCHAR   Name[1];
} IMAGEHLP_SYMBOLW64, *PIMAGEHLP_SYMBOLW64;