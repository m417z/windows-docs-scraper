BOOL FaxDevVirtualDeviceCreation(
  [out] LPDWORD   DeviceCount,
  [out] LPWSTR    DeviceNamePrefix,
  [out] LPDWORD   DeviceIdPrefix,
  [in]  HANDLE    CompletionPort,
  [in]  ULONG_PTR CompletionKey
);