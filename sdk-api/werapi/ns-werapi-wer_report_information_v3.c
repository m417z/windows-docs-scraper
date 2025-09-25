typedef struct _WER_REPORT_INFORMATION_V3 {
  DWORD  dwSize;
  HANDLE hProcess;
  WCHAR  wzConsentKey[64];
  WCHAR  wzFriendlyEventName[128];
  WCHAR  wzApplicationName[128];
  WCHAR  wzApplicationPath[MAX_PATH];
  WCHAR  wzDescription[512];
  HWND   hwndParent;
  WCHAR  wzNamespacePartner[64];
  WCHAR  wzNamespaceGroup[64];
} WER_REPORT_INFORMATION_V3, *PWER_REPORT_INFORMATION_V3;