typedef struct _LINEATTRS {
  FLONG       fl;
  ULONG       iJoin;
  ULONG       iEndCap;
  FLOAT_LONG  elWidth;
  FLOATL      eMiterLimit;
  ULONG       cstyle;
  PFLOAT_LONG pstyle;
  FLOAT_LONG  elStyleState;
} LINEATTRS, *PLINEATTRS;