HRESULT SLSetGenuineInformation(
  [in]           const SLID *pQueryId,
  [in]           PCWSTR     pwszValueName,
  [in]           SLDATATYPE eDataType,
  [in, optional] UINT       cbValue,
  [in, optional] const BYTE *pbValue
);