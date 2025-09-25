typedef struct _IFIEXTRA {
  ULONG   ulIdentifier;
  PTRDIFF dpFontSig;
  ULONG   cig;
  PTRDIFF dpDesignVector;
  PTRDIFF dpAxesInfoW;
  ULONG   aulReserved[1];
} IFIEXTRA, *PIFIEXTRA;