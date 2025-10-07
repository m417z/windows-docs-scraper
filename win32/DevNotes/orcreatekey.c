DWORD ORCreateKey(
  _In_      ORHKEY               Handle,
  _In_      PCWSTR               lpSubKey,
  _In_opt_  PWSTR                lpClass,
  _In_opt_  DWORD                dwOptions,
  _In_opt_  PSECURITY_DESCRIPTOR pSecurityDescriptor,
  _Out_     PORHKEY              phkResult,
  _Out_opt_ PDWORD               pdwDisposition
);