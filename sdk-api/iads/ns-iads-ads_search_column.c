typedef struct ads_search_column {
  LPWSTR    pszAttrName;
  ADSTYPE   dwADsType;
  PADSVALUE pADsValues;
  DWORD     dwNumValues;
  HANDLE    hReserved;
} ADS_SEARCH_COLUMN, *PADS_SEARCH_COLUMN;