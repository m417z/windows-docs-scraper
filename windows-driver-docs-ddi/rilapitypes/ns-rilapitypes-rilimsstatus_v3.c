typedef struct RILIMSSTATUS_V3 {
  DWORD            cbSize;
  DWORD            dwParams;
  DWORD            dwExecutor;
  HUICCAPP         hUiccApp;
  DWORD            dwAvailableServices;
  RILSMSFORMAT     dwSMSSupportedFormat;
  WCHAR            wszServingDomain[256];
  RILIMSSYSTEMTYPE dwIMSSystemType;
} RILIMSSTATUS_V3, *LPRILIMSSTATUS_V3;