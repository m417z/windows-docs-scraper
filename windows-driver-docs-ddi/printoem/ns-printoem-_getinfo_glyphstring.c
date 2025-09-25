typedef struct _GETINFO_GLYPHSTRING {
  DWORD dwSize;
  DWORD dwCount;
  DWORD dwTypeIn;
  PVOID pGlyphIn;
  DWORD dwTypeOut;
  PVOID pGlyphOut;
  DWORD dwGlyphOutSize;
} GETINFO_GLYPHSTRING, *PGETINFO_GLYPHSTRING;