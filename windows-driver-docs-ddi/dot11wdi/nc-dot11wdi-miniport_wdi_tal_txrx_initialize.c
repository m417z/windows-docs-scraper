MINIPORT_WDI_TAL_TXRX_INITIALIZE MiniportWdiTalTxrxInitialize;

NDIS_STATUS MiniportWdiTalTxrxInitialize(
  [in]      NDIS_HANDLE MiniportAdapterContext,
  [in]      NDIS_HANDLE NdisMiniportDataPathHandle,
  [in]      PNDIS_WDI_DATA_API NdisWdiDataPathApi,
  [out]     PTAL_TXRX_HANDLE pMiniportTalTxRxContext,
  [in, out] PNDIS_MINIPORT_WDI_DATA_HANDLERS pMiniportDataHandlers,
  [out]     UINT32 *pMiniportWdiFrameMetadataExtraSpace
)
{...}