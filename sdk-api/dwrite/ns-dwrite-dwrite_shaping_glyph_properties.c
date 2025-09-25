struct DWRITE_SHAPING_GLYPH_PROPERTIES {
  UINT16 justification : 4;
  UINT16 isClusterStart : 1;
  UINT16 isDiacritic : 1;
  UINT16 isZeroWidthSpace : 1;
  UINT16 reserved : 9;
};