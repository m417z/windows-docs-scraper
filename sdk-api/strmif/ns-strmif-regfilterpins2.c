typedef struct REGFILTERPINS2 {
  DWORD              dwFlags;
  UINT               cInstances;
  UINT               nMediaTypes;
  const REGPINTYPES  *lpMediaType;
  UINT               nMediums;
  const REGPINMEDIUM *lpMedium;
  const CLSID        *clsPinCategory;
} REGFILTERPINS2;