typedef struct tACMFILTERDETAILS {
  DWORD        cbStruct;
  DWORD        dwFilterIndex;
  DWORD        dwFilterTag;
  DWORD        fdwSupport;
  LPWAVEFILTER pwfltr;
  DWORD        cbwfltr;
  char         szFilter[ACMFILTERDETAILS_FILTER_CHARS];
} ACMFILTERDETAILS, *PACMFILTERDETAILS, *LPACMFILTERDETAILS;