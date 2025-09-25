typedef struct {
  DWORD dwSize;
  POINT ptOffset;
  PSTR  pHalftoneOption;
  BOOL  bBanding;
  BOOL  bBlankBand;
} IPPARAMS, *PIPPARAMS;