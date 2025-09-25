BOOL OpenThreadToken(
  [in]  HANDLE  ThreadHandle,
  [in]  DWORD   DesiredAccess,
  [in]  BOOL    OpenAsSelf,
  [out] PHANDLE TokenHandle
);