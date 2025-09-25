typedef struct _WIA_DITHER_PATTERN_DATA {
  LONG lSize;
  BSTR bstrPatternName;
  LONG lPatternWidth;
  LONG lPatternLength;
  LONG cbPattern;
  BYTE *pbPattern;
} WIA_DITHER_PATTERN_DATA, *PWIA_DITHER_PATTERN_DATA;