typedef struct tagTVITEMA {
  UINT      mask;
  HTREEITEM hItem;
  UINT      state;
  UINT      stateMask;
  LPSTR     pszText;
  int       cchTextMax;
  int       iImage;
  int       iSelectedImage;
  int       cChildren;
  LPARAM    lParam;
} TVITEMA, *LPTVITEMA;