BOOL GetFileSecurityW(
  [in]            LPCWSTR              lpFileName,
  [in]            SECURITY_INFORMATION RequestedInformation,
  [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]            DWORD                nLength,
  [out]           LPDWORD              lpnLengthNeeded
);