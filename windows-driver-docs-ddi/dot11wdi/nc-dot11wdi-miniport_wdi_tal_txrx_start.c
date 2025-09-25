MINIPORT_WDI_TAL_TXRX_START MiniportWdiTalTxrxStart;

NDIS_STATUS MiniportWdiTalTxrxStart(
  [in]  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  [in]  PWDI_TXRX_TARGET_CONFIGURATION pWifiTxRxConfiguration,
  [out] PTAL_TXRX_PARAMETERS pTalTxRxParameters
)
{...}