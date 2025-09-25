typedef struct _ads_attr_info {
  LPWSTR    pszAttrName;
  DWORD     dwControlCode;
  ADSTYPE   dwADsType;
  PADSVALUE pADsValues;
  DWORD     dwNumValues;
} ADS_ATTR_INFO, *PADS_ATTR_INFO;