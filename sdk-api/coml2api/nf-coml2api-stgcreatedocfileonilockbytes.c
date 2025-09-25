HRESULT StgCreateDocfileOnILockBytes(
  [in]  ILockBytes *plkbyt,
  [in]  DWORD      grfMode,
  [in]  DWORD      reserved,
  [out] IStorage   **ppstgOpen
);