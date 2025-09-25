HRESULT GetMethodProps(
  [in]  mdMethodDef     tkMethodDef,
  [out] mdTypeDef       *ptkClass,
  [out] LPWSTR          szMethod,
  [in]  ULONG           cchMethod,
  [out] ULONG           *pchMethod,
  [out] DWORD           *pdwAttr,
  [out] PCCOR_SIGNATURE *ppvSigBlob,
  [out] ULONG           *pcbSigBlob,
  [out] ULONG           *pulCodeRVA,
  [out] DWORD           *pdwImplFlags
);