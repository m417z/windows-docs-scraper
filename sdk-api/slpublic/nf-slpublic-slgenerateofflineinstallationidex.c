HRESULT SLGenerateOfflineInstallationIdEx(
  [in]           HSLC                            hSLC,
  [in, optional] const SLID                      *pProductSkuId,
  [in, optional] const SL_ACTIVATION_INFO_HEADER *pActivationInfo,
  [out]          PWSTR                           *ppwszInstallationId
);