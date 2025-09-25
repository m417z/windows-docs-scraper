HRESULT SLGetLicensingStatusInformation(
  [in]           HSLC                hSLC,
  [in, optional] const SLID          *pAppID,
  [in, optional] const SLID          *pProductSkuId,
  [in, optional] PCWSTR              pwszRightName,
  [out]          UINT                *pnStatusCount,
  [out]          SL_LICENSING_STATUS **ppLicensingStatus
);