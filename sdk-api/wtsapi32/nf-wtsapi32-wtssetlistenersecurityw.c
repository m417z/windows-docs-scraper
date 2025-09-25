BOOL WTSSetListenerSecurityW(
  [in] HANDLE               hServer,
  [in] PVOID                pReserved,
  [in] DWORD                Reserved,
  [in] LPWSTR               pListenerName,
  [in] SECURITY_INFORMATION SecurityInformation,
  [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);