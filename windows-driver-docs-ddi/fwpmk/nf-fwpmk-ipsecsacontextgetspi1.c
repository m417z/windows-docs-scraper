NTSTATUS IPsecSaContextGetSpi1(
  [in]  HANDLE              engineHandle,
  [in]  UINT64              id,
  [in]  const IPSEC_GETSPI1 *getSpi,
  [out] IPSEC_SA_SPI        *inboundSpi
);