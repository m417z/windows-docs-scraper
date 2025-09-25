DWORD ResUtilSetResourceServiceStartParameters(
  [in]      LPCWSTR            pszServiceName,
  [in]      SC_HANDLE          schSCMHandle,
  [in, out] LPSC_HANDLE        phService,
  [in]      PLOG_EVENT_ROUTINE pfnLogEvent,
  [in]      RESOURCE_HANDLE    hResourceHandle
);