typedef struct {
  DWORD_PTR dwCallback;
  UINT      wDeviceID;
  WORD      wReserved0;
  LPWSTR    lpstrDeviceType;
  LPWSTR    lpstrElementName;
  LPWSTR    lpstrAlias;
  DWORD     dwStyle;
  HWND      hWndParent;
  WORD      wReserved1;
} MCI_DGV_OPEN_PARMSW;