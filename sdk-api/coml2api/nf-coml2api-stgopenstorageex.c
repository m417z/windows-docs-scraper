HRESULT StgOpenStorageEx(
  [in]      const WCHAR          *pwcsName,
  [in]      DWORD                grfMode,
  [in]      DWORD                stgfmt,
  [in]      DWORD                grfAttrs,
  [in, out] STGOPTIONS           *pStgOptions,
  [in]      PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]      REFIID               riid,
  [out]     void                 **ppObjectOpen
);