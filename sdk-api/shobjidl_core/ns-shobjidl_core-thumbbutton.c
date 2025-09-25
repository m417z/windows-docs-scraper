typedef struct THUMBBUTTON {
  THUMBBUTTONMASK  dwMask;
  UINT             iId;
  UINT             iBitmap;
  HICON            hIcon;
  WCHAR            szTip[260];
  THUMBBUTTONFLAGS dwFlags;
} THUMBBUTTON, *LPTHUMBBUTTON;