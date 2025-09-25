typedef struct tagTVITEMEXW {
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
  int       iIntegral;
  UINT      uStateEx;
  HWND      hwnd;
  int       iExpandedImage;
  int       iReserved;
} TVITEMEXW, *LPTVITEMEXW;