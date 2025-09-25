BOOL WTSGetListenerSecurityW(
  [in]            HANDLE               hServer,
  [in]            PVOID                pReserved,
  [in]            DWORD                Reserved,
  [in]            LPWSTR               pListenerName,
  [in]            SECURITY_INFORMATION SecurityInformation,
  [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]            DWORD                nLength,
  [out]           LPDWORD              lpnLengthNeeded
);