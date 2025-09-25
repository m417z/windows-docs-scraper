typedef struct _UFF_FONTDIRECTORY {
  DWORD dwSignature;
  WORD  wSize;
  WORD  wFontID;
  SHORT sGlyphID;
  WORD  wFlags;
  DWORD dwInstallerSig;
  DWORD offFontName;
  DWORD offCartridgeName;
  DWORD offFontData;
  DWORD offGlyphData;
  DWORD offVarData;
} UFF_FONTDIRECTORY, *PUFF_FONTDIRECTORY;