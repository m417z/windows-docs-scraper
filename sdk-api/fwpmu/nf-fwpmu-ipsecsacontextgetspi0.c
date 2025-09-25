DWORD IPsecSaContextGetSpi0(
  [in]  HANDLE              engineHandle,
  [in]  UINT64              id,
  [in]  const IPSEC_GETSPI0 *getSpi,
  [out] IPSEC_SA_SPI        *inboundSpi
);