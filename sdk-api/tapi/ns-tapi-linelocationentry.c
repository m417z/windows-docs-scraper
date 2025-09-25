typedef struct linelocationentry_tag {
  DWORD dwPermanentLocationID;
  DWORD dwLocationNameSize;
  DWORD dwLocationNameOffset;
  DWORD dwCountryCode;
  DWORD dwCityCodeSize;
  DWORD dwCityCodeOffset;
  DWORD dwPreferredCardID;
  DWORD dwLocalAccessCodeSize;
  DWORD dwLocalAccessCodeOffset;
  DWORD dwLongDistanceAccessCodeSize;
  DWORD dwLongDistanceAccessCodeOffset;
  DWORD dwTollPrefixListSize;
  DWORD dwTollPrefixListOffset;
  DWORD dwCountryID;
  DWORD dwOptions;
  DWORD dwCancelCallWaitingSize;
  DWORD dwCancelCallWaitingOffset;
} LINELOCATIONENTRY, *LPLINELOCATIONENTRY;