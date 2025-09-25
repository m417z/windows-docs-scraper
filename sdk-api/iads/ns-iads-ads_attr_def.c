typedef struct _ads_attr_def {
  LPWSTR  pszAttrName;
  ADSTYPE dwADsType;
  DWORD   dwMinRange;
  DWORD   dwMaxRange;
  BOOL    fMultiValued;
} ADS_ATTR_DEF, *PADS_ATTR_DEF;