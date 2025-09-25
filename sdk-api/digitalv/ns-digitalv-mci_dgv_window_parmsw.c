typedef struct {
  DWORD_PTR dwCallback;
  HWND      hWnd;
  WORD      wReserved1;
  UINT      nCmdShow;
  WORD      wReserved2;
  LPWSTR    lpstrText;
} MCI_DGV_WINDOW_PARMSW;