typedef struct _ads_sortkey {
  LPWSTR  pszAttrType;
  LPWSTR  pszReserved;
  BOOLEAN fReverseorder;
} ADS_SORTKEY, *PADS_SORTKEY;