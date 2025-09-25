typedef struct {
  DWORD       dwSize;
  DWORD       dwMask;
  SHELLVIEWID *pvid;
  LPWSTR      pszWebViewTemplate;
  DWORD       cchWebViewTemplate;
  LPWSTR      pszWebViewTemplateVersion;
  LPWSTR      pszInfoTip;
  DWORD       cchInfoTip;
  CLSID       *pclsid;
  DWORD       dwFlags;
  LPWSTR      pszIconFile;
  DWORD       cchIconFile;
  int         iIconIndex;
  LPWSTR      pszLogo;
  DWORD       cchLogo;
} SHFOLDERCUSTOMSETTINGS, *LPSHFOLDERCUSTOMSETTINGS;