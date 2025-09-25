NDIS_WDI_RX_INORDER_DATA_IND NdisWdiRxInorderDataInd;

void NdisWdiRxInorderDataInd(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  WDI_RX_INDICATION_LEVEL IndicationLevel,
  WDI_PEER_ID PeerId,
  WDI_EXTENDED_TID ExTid,
  PNDIS_RECEIVE_THROTTLE_PARAMETERS pRxThrottleParams,
  NDIS_STATUS *pWifiStatus
)
{...}