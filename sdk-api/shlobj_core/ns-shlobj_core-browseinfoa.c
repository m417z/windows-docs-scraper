typedef struct _browseinfoA {
  HWND              hwndOwner;
  PCIDLIST_ABSOLUTE pidlRoot;
  LPSTR             pszDisplayName;
  LPCSTR            lpszTitle;
  UINT              ulFlags;
  BFFCALLBACK       lpfn;
  LPARAM            lParam;
  int               iImage;
} BROWSEINFOA, *PBROWSEINFOA, *LPBROWSEINFOA;