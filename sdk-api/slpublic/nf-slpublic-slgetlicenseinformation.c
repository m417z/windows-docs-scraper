HRESULT SLGetLicenseInformation(
  [in]            HSLC       hSLC,
  [in]            const SLID *pSLLicenseId,
  [in]            PCWSTR     pwszValueName,
  [out, optional] SLDATATYPE *peDataType,
  [out]           UINT       *pcbValue,
  [out]           PBYTE      *ppbValue
);