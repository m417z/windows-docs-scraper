DWORD SetNtmsObjectSecurity(
  [in] HANDLE               hSession,
  [in] LPNTMS_GUID          lpObjectId,
  [in] DWORD                dwType,
  [in] SECURITY_INFORMATION SecurityInformation,
  [in] PSECURITY_DESCRIPTOR lpSecurityDescriptor
);