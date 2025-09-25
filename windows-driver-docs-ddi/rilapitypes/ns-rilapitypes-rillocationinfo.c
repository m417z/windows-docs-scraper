typedef struct RILLOCATIONINFO {
  DWORD cbSize;
  DWORD dwParams;
  DWORD dwExecutor;
  DWORD hUiccApp;
  DWORD dwLocationAreaCode;
  DWORD dwTrackingAreaCode;
  DWORD dwCellID;
} RILLOCATIONINFO, *LPRILLOCATIONINFO;