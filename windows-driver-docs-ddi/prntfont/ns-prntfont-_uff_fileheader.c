typedef struct _UFF_FILEHEADER {
  DWORD dwSignature;
  DWORD dwVersion;
  DWORD dwSize;
  DWORD nFonts;
  DWORD nGlyphSets;
  DWORD nVarData;
  DWORD offFontDir;
  DWORD dwFlags;
  DWORD dwReserved[4];
} UFF_FILEHEADER, *PUFF_FILEHEADER;