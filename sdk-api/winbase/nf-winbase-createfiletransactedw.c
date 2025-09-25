HANDLE CreateFileTransactedW(
  [in]           LPCWSTR               lpFileName,
  [in]           DWORD                 dwDesiredAccess,
  [in]           DWORD                 dwShareMode,
  [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [in]           DWORD                 dwCreationDisposition,
  [in]           DWORD                 dwFlagsAndAttributes,
  [in, optional] HANDLE                hTemplateFile,
  [in]           HANDLE                hTransaction,
  [in, optional] PUSHORT               pusMiniVersion,
                 PVOID                 lpExtendedParameter
);