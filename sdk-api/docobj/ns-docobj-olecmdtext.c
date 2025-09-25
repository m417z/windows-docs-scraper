typedef struct _tagOLECMDTEXT {
  DWORD   cmdtextf;
  ULONG   cwActual;
  ULONG   cwBuf;
  wchar_t rgwz[1];
} OLECMDTEXT;