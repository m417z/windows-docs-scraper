typedef struct _ADRENTRY {
  ULONG        ulReserved1;
  ULONG        cValues;
  LPSPropValue rgPropVals;
} ADRENTRY, *LPADRENTRY;