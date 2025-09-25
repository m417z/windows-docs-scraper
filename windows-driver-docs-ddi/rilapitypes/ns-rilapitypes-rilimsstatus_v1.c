typedef struct RILIMSSTATUS_V1 {
  DWORD        cbSize;
  DWORD        dwParams;
  DWORD        dwExecutor;
  HUICCAPP     hUiccApp;
  DWORD        dwAvailableServices;
  RILSMSFORMAT dwSMSSupportedFormat;
} RILIMSSTATUS_V1, *LPRILIMSSTATUS_V1;