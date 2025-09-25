typedef struct {
  DWORD status;
#if ...
  CHAR  *pDomain;
#if ...
  CHAR  *pName;
#else
  LPSTR pDomain;
#endif
#else
  LPSTR pName;
#endif
} DS_NAME_RESULT_ITEMA, *PDS_NAME_RESULT_ITEMA;