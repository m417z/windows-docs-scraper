HRESULT SLGetApplicationInformation(
  [in]            HSLC       hSLC,
  [in]            const SLID *pApplicationId,
  [in]            PCWSTR     pwszValueName,
  [out, optional] SLDATATYPE *peDataType,
  [out]           UINT       *pcbValue,
  [out]           PBYTE      *ppbValue
);