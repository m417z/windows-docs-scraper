HRESULT CreateRootSignature(
  [in]  UINT       nodeMask,
  [in]  const void *pBlobWithRootSignature,
  [in]  SIZE_T     blobLengthInBytes,
        REFIID     riid,
  [out] void       **ppvRootSignature
);