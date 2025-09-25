HRESULT SLDepositOfflineConfirmationIdEx(
  [in]           HSLC                            hSLC,
  [in, optional] const SLID                      *pProductSkuId,
  [in, optional] const SL_ACTIVATION_INFO_HEADER *pActivationInfo,
  [in]           PCWSTR                          pwszInstallationId,
  [in]           PCWSTR                          pwszConfirmationId
);