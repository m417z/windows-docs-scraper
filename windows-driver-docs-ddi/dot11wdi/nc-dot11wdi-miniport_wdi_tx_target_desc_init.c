MINIPORT_WDI_TX_TARGET_DESC_INIT MiniportWdiTxTargetDescInit;

void MiniportWdiTxTargetDescInit(
  [in]  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  [in]  PNET_BUFFER_LIST pNBL,
  [out] NDIS_STATUS *pWifiStatus
)
{...}