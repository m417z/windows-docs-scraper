HRESULT SLGetGenuineInformationEx(
  [in]            const SLID *pAppId,
  [in]            PCWSTR     pwszValueName,
  [out, optional] SLDATATYPE *peDataType,
  [out]           UINT       *pcbValue,
  [out]           BYTE       **ppbValue
);