BOOL WTSGetListenerSecurityA(
  [in]            HANDLE               hServer,
  [in]            PVOID                pReserved,
  [in]            DWORD                Reserved,
  [in]            LPSTR                pListenerName,
  [in]            SECURITY_INFORMATION SecurityInformation,
  [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]            DWORD                nLength,
  [out]           LPDWORD              lpnLengthNeeded
);