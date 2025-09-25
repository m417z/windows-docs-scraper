HRESULT SLGetProductSkuInformation(
  [in]            HSLC       hSLC,
  [in]            const SLID *pProductSkuId,
  [in]            PCWSTR     pwszValueName,
  [out, optional] SLDATATYPE *peDataType,
  [out]           UINT       *pcbValue,
  [out]           PBYTE      *ppbValue
);