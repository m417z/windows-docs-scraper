struct DWRITE_GLYPH_RUN_DESCRIPTION {
  WCHAR const  *localeName;
  WCHAR const  *string;
  UINT32       stringLength;
  UINT16 const *clusterMap;
  UINT32       textPosition;
};