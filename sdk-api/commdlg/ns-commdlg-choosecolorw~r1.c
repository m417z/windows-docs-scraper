typedef struct tagCHOOSECOLORW {
  DWORD        lStructSize;
  HWND         hwndOwner;
  HWND         hInstance;
  COLORREF     rgbResult;
  COLORREF     *lpCustColors;
  DWORD        Flags;
  LPARAM       lCustData;
  LPCCHOOKPROC lpfnHook;
  LPCWSTR      lpTemplateName;
  LPEDITMENU   lpEditInfo;
} CHOOSECOLORW, *LPCHOOSECOLORW;