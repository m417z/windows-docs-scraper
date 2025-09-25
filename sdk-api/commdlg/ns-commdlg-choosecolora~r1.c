typedef struct tagCHOOSECOLORA {
  DWORD        lStructSize;
  HWND         hwndOwner;
  HWND         hInstance;
  COLORREF     rgbResult;
  COLORREF     *lpCustColors;
  DWORD        Flags;
  LPARAM       lCustData;
  LPCCHOOKPROC lpfnHook;
  LPCSTR       lpTemplateName;
  LPEDITMENU   lpEditInfo;
} CHOOSECOLORA, *LPCHOOSECOLORA;