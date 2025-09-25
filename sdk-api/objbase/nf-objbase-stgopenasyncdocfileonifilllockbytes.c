HRESULT StgOpenAsyncDocfileOnIFillLockBytes(
  [in]  IFillLockBytes *pflb,
  [in]  DWORD          grfMode,
  [in]  DWORD          asyncFlags,
  [out] IStorage       **ppstgOpen
);