typedef struct _ADSPROPINITPARAMS {
  DWORD            dwSize;
  DWORD            dwFlags;
  HRESULT          hr;
  IDirectoryObject *pDsObj;
  LPWSTR           pwzCN;
  PADS_ATTR_INFO   pWritableAttrs;
} ADSPROPINITPARAMS, *PADSPROPINITPARAMS;