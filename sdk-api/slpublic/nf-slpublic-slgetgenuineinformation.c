HRESULT SLGetGenuineInformation(
  [in]            const SLID *pQueryId,
  [in]            PCWSTR     pwszValueName,
  [out, optional] SLDATATYPE *peDataType,
  [out]           UINT       *pcbValue,
  [out]           BYTE       **ppbValue
);