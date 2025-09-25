BOOL QueryServiceDynamicInformation(
  [in] SERVICE_STATUS_HANDLE hServiceStatus,
  [in] DWORD                 dwInfoLevel,
       PVOID                 *ppDynamicInfo
);