typedef struct tagCHOOSEFONTA {
  DWORD        lStructSize;
  HWND         hwndOwner;
  HDC          hDC;
  LPLOGFONTA   lpLogFont;
  INT          iPointSize;
  DWORD        Flags;
  COLORREF     rgbColors;
  LPARAM       lCustData;
  LPCFHOOKPROC lpfnHook;
  LPCSTR       lpTemplateName;
  HINSTANCE    hInstance;
  LPSTR        lpszStyle;
  WORD         nFontType;
  WORD         ___MISSING_ALIGNMENT__;
  INT          nSizeMin;
  INT          nSizeMax;
} CHOOSEFONTA;