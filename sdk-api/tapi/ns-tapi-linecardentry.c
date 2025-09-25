typedef struct linecardentry_tag {
  DWORD dwPermanentCardID;
  DWORD dwCardNameSize;
  DWORD dwCardNameOffset;
  DWORD dwCardNumberDigits;
  DWORD dwSameAreaRuleSize;
  DWORD dwSameAreaRuleOffset;
  DWORD dwLongDistanceRuleSize;
  DWORD dwLongDistanceRuleOffset;
  DWORD dwInternationalRuleSize;
  DWORD dwInternationalRuleOffset;
  DWORD dwOptions;
} LINECARDENTRY, *LPLINECARDENTRY;