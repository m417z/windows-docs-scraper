typedef struct _FONTDIFF {
  BYTE   jReserved1;
  BYTE   jReserved2;
  BYTE   jReserved3;
  BYTE   bWeight;
  USHORT usWinWeight;
  FSHORT fsSelection;
  FWORD  fwdAveCharWidth;
  FWORD  fwdMaxCharInc;
  POINTL ptlCaret;
} FONTDIFF;