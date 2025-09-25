BOOL OpenProcessToken(
  [in]  HANDLE  ProcessHandle,
  [in]  DWORD   DesiredAccess,
  [out] PHANDLE TokenHandle
);