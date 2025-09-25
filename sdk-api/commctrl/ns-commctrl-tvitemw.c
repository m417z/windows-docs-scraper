typedef struct tagTVITEMW {
  UINT      mask;
  HTREEITEM hItem;
  UINT      state;
  UINT      stateMask;
  LPWSTR    pszText;
  int       cchTextMax;
  int       iImage;
  int       iSelectedImage;
  int       cChildren;
  LPARAM    lParam;
} TVITEMW, *LPTVITEMW;