typedef struct RILEMERGENCYNUMBER {
  DWORD    cbSize;
  DWORD    dwParams;
  DWORD    dwExecutor;
  HUICCAPP hUiccApp;
  DWORD    dwCategory;
  WCHAR    wszEmergencyNumber[8];
} RILEMERGENCYNUMBER, *LPRILEMERGENCYNUMBER;