NDIS_WDI_TX_INJECT_FRAME_IND NdisWdiTxInjectFrameInd;

void NdisWdiTxInjectFrameInd(
  [in] NDIS_HANDLE NdisMiniportDataPathHandle,
  [in] WDI_PORT_ID PortId,
  [in] WDI_PEER_ID PeerId,
  [in] WDI_EXTENDED_TID ExTid,
  [in] PNET_BUFFER_LIST pNBL,
  [in] BOOLEAN bIsUnicast,
  [in] BOOLEAN bUseLegacyRates,
  [in] UINT16 Ethertype,
  [in] WDI_EXEMPTION_ACTION_TYPE ExemptionAction
)
{...}