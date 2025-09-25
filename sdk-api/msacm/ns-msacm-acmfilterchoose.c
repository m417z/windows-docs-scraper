typedef struct tACMFILTERCHOOSE {
  DWORD                   cbStruct;
  DWORD                   fdwStyle;
  HWND                    hwndOwner;
  LPWAVEFILTER            pwfltr;
  DWORD                   cbwfltr;
  LPCSTR                  pszTitle;
  char                    szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
  char                    szFilter[ACMFILTERDETAILS_FILTER_CHARS];
  LPSTR                   pszName;
  DWORD                   cchName;
  DWORD                   fdwEnum;
  LPWAVEFILTER            pwfltrEnum;
  HINSTANCE               hInstance;
  LPCSTR                  pszTemplateName;
  LPARAM                  lCustData;
  ACMFILTERCHOOSEHOOKPROC pfnHook;
} ACMFILTERCHOOSE, *PACMFILTERCHOOSE, *LPACMFILTERCHOOSE;