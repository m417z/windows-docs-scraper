MINIPORT_WDI_RX_PPDU_RSSI MiniportWdiRxPpduRssi;

void MiniportWdiRxPpduRssi(
  [in]  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  [in]  PNET_BUFFER_LIST pNBL,
  [out] UINT8 *pRssi
)
{...}