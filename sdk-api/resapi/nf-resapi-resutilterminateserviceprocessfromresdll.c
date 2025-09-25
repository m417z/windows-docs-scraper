DWORD ResUtilTerminateServiceProcessFromResDll(
  [in]            DWORD              dwServicePid,
  [in]            BOOL               bOffline,
  [out, optional] PDWORD             pdwResourceState,
  [in]            PLOG_EVENT_ROUTINE pfnLogEvent,
  [in]            RESOURCE_HANDLE    hResourceHandle
);