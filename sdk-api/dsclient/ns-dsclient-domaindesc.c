typedef struct _DOMAINDESC {
  LPWSTR             pszName;
  LPWSTR             pszPath;
  LPWSTR             pszNCName;
  LPWSTR             pszTrustParent;
  LPWSTR             pszObjectClass;
  ULONG              ulFlags;
  BOOL               fDownLevel;
  struct _DOMAINDESC *pdChildList;
  struct _DOMAINDESC *pdNextSibling;
} DOMAIN_DESC, DOMAINDESC, *PDOMAIN_DESC, *LPDOMAINDESC;