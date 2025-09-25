HRESULT GetFieldProps(
  [in]  mdFieldDef      tkFieldDef,
  [out] mdTypeDef       *ptkTypeDef,
  [out] LPWSTR          szField,
  [in]  ULONG           cchField,
  [out] ULONG           *pchField,
  [out] DWORD           *pdwAttr,
  [out] PCCOR_SIGNATURE *ppvSigBlob,
  [out] ULONG           *pcbSigBlob,
  [out] DWORD           *pdwCPlusTypeFlag,
  [out] UVCP_CONSTANT   *ppValue,
  [out] ULONG           *pcchValue
);