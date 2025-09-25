HRESULT StgOpenStorageOnILockBytes(
  [in]  ILockBytes *plkbyt,
  [in]  IStorage   *pstgPriority,
  [in]  DWORD      grfMode,
  [in]  SNB        snbExclude,
  [in]  DWORD      reserved,
  [out] IStorage   **ppstgOpen
);