typedef struct _SV2CVW2_PARAMS {
  DWORD             cbSize;
  IShellView        *psvPrev;
  LPCFOLDERSETTINGS pfs;
  IShellBrowser     *psbOwner;
  RECT              *prcView;
  const SHELLVIEWID *pvid;
  HWND              hwndView;
} SV2CVW2_PARAMS, *LPSV2CVW2_PARAMS;