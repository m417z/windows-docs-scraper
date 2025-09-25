typedef struct tagTEXT_SOURCE {
  PFNFILLTEXTBUFFER pfnFillTextBuffer;
  const WCHAR       *awcBuffer;
  ULONG             iEnd;
  ULONG             iCur;
} TEXT_SOURCE;