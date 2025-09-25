typedef struct _IMAGEHLP_DUPLICATE_SYMBOL {
  DWORD            SizeOfStruct;
  DWORD            NumberOfDups;
  PIMAGEHLP_SYMBOL Symbol;
  DWORD            SelectedSymbol;
} IMAGEHLP_DUPLICATE_SYMBOL, *PIMAGEHLP_DUPLICATE_SYMBOL;