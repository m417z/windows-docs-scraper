typedef struct _WER_REPORT_INFORMATION {
  DWORD  dwSize;
  HANDLE hProcess;
  WCHAR  wzConsentKey[64];
  WCHAR  wzFriendlyEventName[128];
  WCHAR  wzApplicationName[128];
  WCHAR  wzApplicationPath[MAX_PATH];
  WCHAR  wzDescription[512];
  HWND   hwndParent;
} WER_REPORT_INFORMATION, *PWER_REPORT_INFORMATION;