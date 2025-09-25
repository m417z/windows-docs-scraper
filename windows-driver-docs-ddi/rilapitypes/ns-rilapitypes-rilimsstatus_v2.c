typedef struct RILIMSSTATUS_V2 {
  DWORD        cbSize;
  DWORD        dwParams;
  DWORD        dwExecutor;
  HUICCAPP     hUiccApp;
  DWORD        dwAvailableServices;
  RILSMSFORMAT dwSMSSupportedFormat;
  WCHAR        wszServingDomain[256];
} RILIMSSTATUS_V2, *LPRILIMSSTATUS_V2;