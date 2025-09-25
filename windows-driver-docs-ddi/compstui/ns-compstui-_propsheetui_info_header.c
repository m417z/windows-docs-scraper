typedef struct _PROPSHEETUI_INFO_HEADER {
  WORD      cbSize;
  WORD      Flags;
  LPTSTR    pTitle;
  HWND      hWndParent;
  HINSTANCE hInst;
  union {
    HICON     hIcon;
    ULONG_PTR IconID;
  } DUMMYUNIONNAME;
} PROPSHEETUI_INFO_HEADER, *PPROPSHEETUI_INFO_HEADER;