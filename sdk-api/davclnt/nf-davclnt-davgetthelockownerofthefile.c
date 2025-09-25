DWORD DavGetTheLockOwnerOfTheFile(
  [in]            LPCWSTR FileName,
  [out, optional] PWSTR   LockOwnerName,
  [in, out]       PULONG  LockOwnerNameLengthInBytes
);