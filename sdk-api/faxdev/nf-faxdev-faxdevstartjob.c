BOOL FaxDevStartJob(
  [in]  HLINE     LineHandle,
  [in]  DWORD     DeviceId,
  [out] PHANDLE   FaxHandle,
  [in]  HANDLE    CompletionPortHandle,
  [in]  ULONG_PTR CompletionKey
);