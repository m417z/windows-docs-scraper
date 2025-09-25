typedef struct tag_SCRIPT_ANALYSIS {
  WORD         eScript : 10;
  WORD         fRTL : 1;
  WORD         fLayoutRTL : 1;
  WORD         fLinkBefore : 1;
  WORD         fLinkAfter : 1;
  WORD         fLogicalOrder : 1;
  WORD         fNoGlyphIndex : 1;
  SCRIPT_STATE s;
} SCRIPT_ANALYSIS;