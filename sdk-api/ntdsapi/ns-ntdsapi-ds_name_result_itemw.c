typedef struct {
  DWORD  status;
#if ...
  WCHAR  *pDomain;
#if ...
  WCHAR  *pName;
#else
  LPWSTR pDomain;
#endif
#else
  LPWSTR pName;
#endif
} DS_NAME_RESULT_ITEMW, *PDS_NAME_RESULT_ITEMW;