typedef struct linecountryentry_tag {
  DWORD dwCountryID;
  DWORD dwCountryCode;
  DWORD dwNextCountryID;
  DWORD dwCountryNameSize;
  DWORD dwCountryNameOffset;
  DWORD dwSameAreaRuleSize;
  DWORD dwSameAreaRuleOffset;
  DWORD dwLongDistanceRuleSize;
  DWORD dwLongDistanceRuleOffset;
  DWORD dwInternationalRuleSize;
  DWORD dwInternationalRuleOffset;
} LINECOUNTRYENTRY, *LPLINECOUNTRYENTRY;