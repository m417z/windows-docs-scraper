typedef struct _enprotected {
  NMHDR     nmhdr;
  UINT      msg;
  WPARAM    wParam;
  LPARAM    lParam;
  CHARRANGE chrg;
} ENPROTECTED;