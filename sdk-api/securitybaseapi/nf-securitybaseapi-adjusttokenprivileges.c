BOOL AdjustTokenPrivileges(
  [in]            HANDLE            TokenHandle,
  [in]            BOOL              DisableAllPrivileges,
  [in, optional]  PTOKEN_PRIVILEGES NewState,
  [in]            DWORD             BufferLength,
  [out, optional] PTOKEN_PRIVILEGES PreviousState,
  [out, optional] PDWORD            ReturnLength
);