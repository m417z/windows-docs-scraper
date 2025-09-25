HRESULT RtwqLockSharedWorkQueue(
  [in]      PCWSTR usageClass,
  [in]      LONG   basePriority,
  [in, out] DWORD  *taskId,
  [out]     DWORD  *id
);