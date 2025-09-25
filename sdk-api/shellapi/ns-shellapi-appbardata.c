typedef struct _AppBarData {
  DWORD  cbSize;
  HWND   hWnd;
  UINT   uCallbackMessage;
  UINT   uEdge;
  RECT   rc;
  LPARAM lParam;
} APPBARDATA, *PAPPBARDATA;