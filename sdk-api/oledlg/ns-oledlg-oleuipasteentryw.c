typedef struct tagOLEUIPASTEENTRYW {
  FORMATETC fmtetc;
  LPCWSTR   lpstrFormatName;
  LPCWSTR   lpstrResultText;
  DWORD     dwFlags;
  DWORD     dwScratchSpace;
} OLEUIPASTEENTRYW, *POLEUIPASTEENTRYW, *LPOLEUIPASTEENTRYW;