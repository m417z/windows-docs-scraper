typedef struct _browseinfoW {
  HWND              hwndOwner;
  PCIDLIST_ABSOLUTE pidlRoot;
  LPWSTR            pszDisplayName;
  LPCWSTR           lpszTitle;
  UINT              ulFlags;
  BFFCALLBACK       lpfn;
  LPARAM            lParam;
  int               iImage;
} BROWSEINFOW, *PBROWSEINFOW, *LPBROWSEINFOW;