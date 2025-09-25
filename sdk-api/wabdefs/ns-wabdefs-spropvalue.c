typedef struct _SPropValue {
  ULONG ulPropTag;
  ULONG dwAlignPad;
  _PV   Value;
  union _PV;
} SPropValue, *LPSPropValue;