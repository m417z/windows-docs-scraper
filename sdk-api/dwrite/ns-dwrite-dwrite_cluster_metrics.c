struct DWRITE_CLUSTER_METRICS {
  FLOAT  width;
  UINT16 length;
  UINT16 canWrapLineAfter : 1;
  UINT16 isWhitespace : 1;
  UINT16 isNewline : 1;
  UINT16 isSoftHyphen : 1;
  UINT16 isRightToLeft : 1;
  UINT16 padding : 11;
};