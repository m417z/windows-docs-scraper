typedef struct _enlink {
  NMHDR     nmhdr;
  UINT      msg;
  WPARAM    wParam;
  LPARAM    lParam;
  CHARRANGE chrg;
} ENLINK;