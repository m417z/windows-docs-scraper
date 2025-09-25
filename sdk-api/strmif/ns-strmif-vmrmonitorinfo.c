typedef struct tagVMRMONITORINFO {
  VMRGUID       guid;
  RECT          rcMonitor;
  HMONITOR      hMon;
  DWORD         dwFlags;
  wchar_t       szDevice[32];
  wchar_t       szDescription[256];
  LARGE_INTEGER liDriverVersion;
  DWORD         dwVendorId;
  DWORD         dwDeviceId;
  DWORD         dwSubSysId;
  DWORD         dwRevision;
} VMRMONITORINFO;