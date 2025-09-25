typedef struct tagTVITEMEXA {
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
  int       iIntegral;
  UINT      uStateEx;
  HWND      hwnd;
  int       iExpandedImage;
  int       iReserved;
} TVITEMEXA, *LPTVITEMEXA;