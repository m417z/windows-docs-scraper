HRESULT GetMemberProps(
  [in]  mdToken         tkMember,
  [out] mdTypeDef       *ptkTypeDef,
  [out] LPWSTR          szMember,
  [in]  ULONG           cchMember,
  [out] ULONG           *pchMember,
  [out] DWORD           *pdwAttr,
  [out] PCCOR_SIGNATURE *ppvSigBlob,
  [out] ULONG           *pcbSigBlob,
  [out] ULONG           *pulCodeRVA,
  [out] DWORD           *pdwImplFlags,
  [out] DWORD           *pdwCPlusTypeFlag,
  [out] UVCP_CONSTANT   *ppValue,
  [out] ULONG           *pcchValue
);