typedef struct RILMESSAGEINUICC {
  DWORD    cbSize;
  DWORD    dwExecutor;
  HUICCAPP hUiccApp;
  DWORD    dwIndex;
} RILMESSAGEINUICC, *LPRILMESSAGEINUICC;