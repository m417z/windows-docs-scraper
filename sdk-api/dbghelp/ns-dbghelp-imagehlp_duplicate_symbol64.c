typedef struct _IMAGEHLP_DUPLICATE_SYMBOL64 {
  DWORD              SizeOfStruct;
  DWORD              NumberOfDups;
  PIMAGEHLP_SYMBOL64 Symbol;
  DWORD              SelectedSymbol;
} IMAGEHLP_DUPLICATE_SYMBOL64, *PIMAGEHLP_DUPLICATE_SYMBOL64;