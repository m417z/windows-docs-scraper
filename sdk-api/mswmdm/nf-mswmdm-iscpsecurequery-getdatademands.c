HRESULT GetDataDemands(
  [out]     UINT     *pfuFlags,
  [out]     DWORD    *pdwMinRightsData,
  [out]     DWORD    *pdwMinExamineData,
  [out]     DWORD    *pdwMinDecideData,
  [in, out] BYTE [8] abMac
);