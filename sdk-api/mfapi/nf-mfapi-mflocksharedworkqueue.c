HRESULT MFLockSharedWorkQueue(
  [in]      PCWSTR wszClass,
  [in]      LONG   BasePriority,
  [in, out] DWORD  *pdwTaskId,
  [out]     DWORD  *pID
);