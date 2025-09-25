typedef struct tagMONMSGSTRUCT {
  UINT                cb;
  HWND                hwndTo;
  DWORD               dwTime;
  HANDLE              hTask;
  UINT                wMsg;
  WPARAM              wParam;
  LPARAM              lParam;
  DDEML_MSG_HOOK_DATA dmhd;
} MONMSGSTRUCT, *PMONMSGSTRUCT;