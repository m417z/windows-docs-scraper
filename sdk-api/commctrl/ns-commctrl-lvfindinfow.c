typedef struct tagLVFINDINFOW {
  UINT    flags;
  LPCWSTR psz;
  LPARAM  lParam;
  POINT   pt;
  UINT    vkDirection;
} LVFINDINFOW, *LPFINDINFOW;