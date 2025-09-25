BOOL WTSSetListenerSecurityA(
  [in] HANDLE               hServer,
  [in] PVOID                pReserved,
  [in] DWORD                Reserved,
  [in] LPSTR                pListenerName,
  [in] SECURITY_INFORMATION SecurityInformation,
  [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);