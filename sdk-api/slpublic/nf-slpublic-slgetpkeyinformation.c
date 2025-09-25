HRESULT SLGetPKeyInformation(
  [in]            HSLC       hSLC,
  [in]            const SLID *pPKeyId,
  [in]            PCWSTR     pwszValueName,
  [out, optional] SLDATATYPE *peDataType,
  [out]           UINT       *pcbValue,
  [out]           PBYTE      *ppbValue
);