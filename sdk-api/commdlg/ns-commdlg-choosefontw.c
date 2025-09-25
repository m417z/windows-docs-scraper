typedef struct tagCHOOSEFONTW {
  DWORD        lStructSize;
  HWND         hwndOwner;
  HDC          hDC;
  LPLOGFONTW   lpLogFont;
  INT          iPointSize;
  DWORD        Flags;
  COLORREF     rgbColors;
  LPARAM       lCustData;
  LPCFHOOKPROC lpfnHook;
  LPCWSTR      lpTemplateName;
  HINSTANCE    hInstance;
  LPWSTR       lpszStyle;
  WORD         nFontType;
  WORD         ___MISSING_ALIGNMENT__;
  INT          nSizeMin;
  INT          nSizeMax;
} CHOOSEFONTW;