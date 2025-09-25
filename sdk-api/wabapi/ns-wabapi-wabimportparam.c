typedef struct _WABIMPORTPARAM {
  ULONG     cbSize;
  LPADRBOOK lpAdrBook;
  HWND      hWnd;
  ULONG     ulFlags;
  LPSTR     lpszFileName;
} WABIMPORTPARAM, *LPWABIMPORTPARAM;