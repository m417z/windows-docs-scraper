HRESULT FindMemberRef(
  [in]  mdTypeRef       tkTypeRef,
  [in]  LPCWSTR         szName,
  [in]  PCCOR_SIGNATURE pvSigBlob,
  [in]  ULONG           cbSigBlob,
  [out] mdMemberRef     *pMemberRef
);