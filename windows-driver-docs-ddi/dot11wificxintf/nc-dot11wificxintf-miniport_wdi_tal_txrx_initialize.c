MINIPORT_WDI_TAL_TXRX_INITIALIZE MiniportWdiTalTxrxInitialize;

NDIS_STATUS MiniportWdiTalTxrxInitialize(
  NDIS_HANDLE MiniportAdapterContext,
  NDIS_HANDLE NdisMiniportDataPathHandle,
  PNDIS_WDI_DATA_API NdisWdiDataPathApi,
  PTAL_TXRX_HANDLE pMiniportTalTxRxContext,
  PNDIS_MINIPORT_WDI_DATA_HANDLERS pMiniportDataHandlers,
  UINT32 *pMiniportWdiFrameMetadataExtraSpace
)
{...}