typedef struct _FD_GLYPHATTR {
  ULONG cjThis;
  ULONG cGlyphs;
  ULONG iMode;
  BYTE  aGlyphAttr[1];
} FD_GLYPHATTR, *PFD_GLYPHATTR;