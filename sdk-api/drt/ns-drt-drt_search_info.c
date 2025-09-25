typedef struct drt_search_info_tag {
  DWORD    dwSize;
  BOOL     fIterative;
  BOOL     fAllowCurrentInstanceMatch;
  BOOL     fAnyMatchInRange;
  ULONG    cMaxEndpoints;
  DRT_DATA *pMaximumKey;
  DRT_DATA *pMinimumKey;
} DRT_SEARCH_INFO, *PDRT_SEARCH_INFO;