HRESULT GetMemberRefProps(
  [in]  mdMemberRef     tkMemberRef,
  [out] mdToken         *ptk,
  [out] LPWSTR          szMember,
  [in]  ULONG           cchMember,
  [out] ULONG           *pchMember,
  [out] PCCOR_SIGNATURE *ppvSigBlob,
  [out] ULONG           *pcbSigBlob
);