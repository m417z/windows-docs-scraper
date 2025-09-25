typedef struct _UNI_GLYPHSETDATA {
  DWORD dwSize;
  DWORD dwVersion;
  DWORD dwFlags;
  LONG  lPredefinedID;
  DWORD dwGlyphCount;
  DWORD dwRunCount;
  DWORD loRunOffset;
  DWORD dwCodePageCount;
  DWORD loCodePageOffset;
  DWORD loMapTableOffset;
  DWORD dwReserved[2];
} UNI_GLYPHSETDATA, *PUNI_GLYPHSETDATA;