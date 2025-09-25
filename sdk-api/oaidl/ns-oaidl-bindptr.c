typedef union tagBINDPTR {
  FUNCDESC  *lpfuncdesc;
  VARDESC   *lpvardesc;
  ITypeComp *lptcomp;
} BINDPTR, *LPBINDPTR;