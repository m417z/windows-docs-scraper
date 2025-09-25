typedef struct _MAPPING_DATA_RANGE {
  DWORD  dwStartIndex;
  DWORD  dwEndIndex;
  LPWSTR pszDescription;
  DWORD  dwDescriptionLength;
  LPVOID pData;
  DWORD  dwDataSize;
  LPWSTR pszContentType;
  LPWSTR *prgActionIds;
  DWORD  dwActionsCount;
  LPWSTR *prgActionDisplayNames;
} MAPPING_DATA_RANGE, *PMAPPING_DATA_RANGE;