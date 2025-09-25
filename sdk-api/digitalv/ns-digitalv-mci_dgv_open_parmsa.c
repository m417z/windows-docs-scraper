typedef struct {
  DWORD_PTR dwCallback;
  UINT      wDeviceID;
  WORD      wReserved0;
  LPSTR     lpstrDeviceType;
  LPSTR     lpstrElementName;
  LPSTR     lpstrAlias;
  DWORD     dwStyle;
  HWND      hWndParent;
  WORD      wReserved1;
} MCI_DGV_OPEN_PARMSA;