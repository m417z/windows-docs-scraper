typedef struct _IMAGEHLP_SYMBOL {
  DWORD SizeOfStruct;
  DWORD Address;
  DWORD Size;
  DWORD Flags;
  DWORD MaxNameLength;
  CHAR  Name[1];
} IMAGEHLP_SYMBOL, *PIMAGEHLP_SYMBOL;