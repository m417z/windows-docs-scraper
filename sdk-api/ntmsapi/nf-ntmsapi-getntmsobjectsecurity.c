DWORD GetNtmsObjectSecurity(
  [in]  HANDLE               hSession,
  [in]  LPNTMS_GUID          lpObjectId,
  [in]  DWORD                dwType,
  [in]  SECURITY_INFORMATION RequestedInformation,
  [out] PSECURITY_DESCRIPTOR lpSecurityDescriptor,
  [in]  DWORD                nLength,
  [out] LPDWORD              lpnLengthNeeded
);