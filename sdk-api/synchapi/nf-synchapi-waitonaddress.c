BOOL WaitOnAddress(
  [in]           volatile VOID *Address,
  [in]           PVOID         CompareAddress,
  [in]           SIZE_T        AddressSize,
  [in, optional] DWORD         dwMilliseconds
);