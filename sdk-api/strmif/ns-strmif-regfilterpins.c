typedef struct REGFILTERPINS {
  LPWSTR            strName;
  BOOL              bRendered;
  BOOL              bOutput;
  BOOL              bZero;
  BOOL              bMany;
  const CLSID       *clsConnectsToFilter;
  const WCHAR       *strConnectsToPin;
  UINT              nMediaTypes;
  const REGPINTYPES *lpMediaType;
} REGFILTERPINS;