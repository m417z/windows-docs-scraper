HRESULT SLActivateProduct(
  [in]           HSLC                            hSLC,
  [in]           const SLID                      *pProductSkuId,
  [in, optional] UINT                            cbAppSpecificData,
  [in, optional] const PVOID                     pvAppSpecificData,
  [in, optional] const SL_ACTIVATION_INFO_HEADER *pActivationInfo,
  [in, optional] PCWSTR                          pwszProxyServer,
  [in, optional] WORD                            wProxyPort
);