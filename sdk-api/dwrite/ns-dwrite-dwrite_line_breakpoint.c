struct DWRITE_LINE_BREAKPOINT {
  UINT8 breakConditionBefore : 2;
  UINT8 breakConditionAfter : 2;
  UINT8 isWhitespace : 1;
  UINT8 isSoftHyphen : 1;
  UINT8 padding : 2;
};