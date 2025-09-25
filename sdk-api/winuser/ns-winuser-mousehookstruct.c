typedef struct tagMOUSEHOOKSTRUCT {
  POINT     pt;
  HWND      hwnd;
  UINT      wHitTestCode;
  ULONG_PTR dwExtraInfo;
} MOUSEHOOKSTRUCT, *LPMOUSEHOOKSTRUCT, *PMOUSEHOOKSTRUCT;