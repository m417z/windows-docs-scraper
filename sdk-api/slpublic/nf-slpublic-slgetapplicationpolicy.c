HRESULT SLGetApplicationPolicy(
  [in]            HSLP       hPolicyContext,
  [in]            PCWSTR     pwszValueName,
  [out, optional] SLDATATYPE *peDataType,
  [out]           UINT       *pcbValue,
  [out]           PBYTE      *ppbValue
);