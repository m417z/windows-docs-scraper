HRESULT EnumerateBackgroundTasks(
  [in]  LPCWSTR packageFullName,
  [out] ULONG   *taskCount,
  [out] LPCGUID *taskIds,
  [out] LPCWSTR **taskNames
);