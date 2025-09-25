typedef struct tagLVSETINFOTIP {
  UINT   cbSize;
  DWORD  dwFlags;
  LPWSTR pszText;
  int    iItem;
  int    iSubItem;
} LVSETINFOTIP, *PLVSETINFOTIP;