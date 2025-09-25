NTSTATUS ExSecurePoolUpdate(
  [in] HANDLE    SecurePoolHandle,
  [in] ULONG     Tag,
  [in] PVOID     Allocation,
  [in] ULONG_PTR Cookie,
  [in] SIZE_T    Offset,
  [in] SIZE_T    Size,
  [in] PVOID     Buffer
);