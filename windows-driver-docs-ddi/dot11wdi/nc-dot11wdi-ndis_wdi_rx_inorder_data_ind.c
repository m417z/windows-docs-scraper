NDIS_WDI_RX_INORDER_DATA_IND NdisWdiRxInorderDataInd;

void NdisWdiRxInorderDataInd(
  [in]  NDIS_HANDLE NdisMiniportDataPathHandle,
  [in]  WDI_RX_INDICATION_LEVEL IndicationLevel,
  [in]  WDI_PEER_ID PeerId,
  [in]  WDI_EXTENDED_TID ExTid,
  [in]  PNDIS_RECEIVE_THROTTLE_PARAMETERS pRxThrottleParams,
  [out] NDIS_STATUS *pWifiStatus
)
{...}