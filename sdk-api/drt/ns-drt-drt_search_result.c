typedef struct drt_search_result_tag {
  DWORD            dwSize;
  DRT_MATCH_TYPE   type;
  PVOID            pvContext;
  DRT_REGISTRATION registration;
} DRT_SEARCH_RESULT, *PDRT_SEARCH_RESULT;