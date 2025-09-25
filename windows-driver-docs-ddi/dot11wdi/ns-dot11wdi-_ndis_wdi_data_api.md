# _NDIS_WDI_DATA_API structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
NDIS_WDI_DATA_API structure specifies the entry points for WDI data indications.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_WDI_DATA_API structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_WDI_DATA_API.

To indicate the version of the NDIS_WDI_DATA_API structure, set the
**Revision** member to the following value:

#### NDIS_OBJECT_TYPE_WDI_DATA_API_REVISION_1

Set the
**Size** member to NDIS_SIZEOF_WDI_DATA_API_REVISION_1.

### `TxDequeueIndication`

The entry point of the [NdisWdiTxDequeueIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_dequeue_ind) callback function.

### `TxTransferCompleteIndication`

The entry point of the [NdisWdiTxTransferCompleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_transfer_complete_ind) callback function.

### `TxSendCompleteIndication`

The entry point of the [NdisWdiTxSendCompleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_complete_ind) callback function.

### `TxQueryRATIDState`

The entry point of the [NdisWdiTxQueryRATIDState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_query_ra_tid_state) callback function.

### `TxSendPauseIndication`

The entry point of the [NdisWdiTxSendPauseIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_pause_ind) callback function.

### `TxSendRestartIndication`

The entry point of the [NdisWdiTxSendRestartIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_restart_ind) callback function.

### `TxReleaseFrameIndication`

The entry point of the [NdisWdiTxReleaseFrameIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_release_frames_ind) callback function.

### `TxInjectFrameIndication`

The entry point of the [NdisWdiTxInjectFrameIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_inject_frame_ind) callback function.

### `TxAbortConfirm`

The entry point of the [NdisWdiTxAbortConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_abort_confirm) callback function.

### `RxInorderDataIndication`

The entry point of the [NdisWdiRxInorderDataIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_rx_inorder_data_ind) callback function.

### `RxStopConfirm`

The entry point of the [NdisWdiRxStopConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_rx_stop_confirm) callback function.

### `RxFlushConfirm`

The entry point of the [NdisWdiRxFlushConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_rx_flush_confirm) callback function.

### `PeerCreateIndication`

The entry point of the [NdisWdiPeerCreateIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_peer_create_ind) callback function.

### `PeerDeleteIndication`

The entry point of the [NdisWdiPeerDeleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_peer_delete_ind) callback function.

### `AllocateWiFiFrameMetaData`

The entry point of the [NdisWdiAllocateWiFiFrameMetaData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_allocate_wdi_frame_metadata) callback function.

### `FreeWiFiFrameMetaData`

The entry point of the [NdisWdiFreeWiFiFrameMetaData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_free_wdi_frame_metadata) callback function.

### `TxQuerySuspectFrameCompleteStatus`

The entry point of the [NdisWdiTxQuerySuspectFrameCompleteStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_query_suspect_frame_complete_status) callback function.