typedef struct tagOLEUIPASTEENTRYA {
  FORMATETC fmtetc;
  LPCSTR    lpstrFormatName;
  LPCSTR    lpstrResultText;
  DWORD     dwFlags;
  DWORD     dwScratchSpace;
} OLEUIPASTEENTRYA, *POLEUIPASTEENTRYA, *LPOLEUIPASTEENTRYA;