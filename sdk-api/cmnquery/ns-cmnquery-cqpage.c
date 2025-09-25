typedef struct _cqpage {
  DWORD        cbStruct;
  DWORD        dwFlags;
  LPCQPAGEPROC pPageProc;
  HINSTANCE    hInstance;
  INT          idPageName;
  INT          idPageTemplate;
  DLGPROC      pDlgProc;
  LPARAM       lParam;
} CQPAGE, *LPCQPAGE;