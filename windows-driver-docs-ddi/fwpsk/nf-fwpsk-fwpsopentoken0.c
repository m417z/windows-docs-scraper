NTSTATUS FwpsOpenToken0(
  [in]  IN HANDLE  engineHandle,
  [in]  IN LUID    modifiedId,
  [in]  IN DWORD   desiredAccess,
  [out] OUT HANDLE *accessToken
);