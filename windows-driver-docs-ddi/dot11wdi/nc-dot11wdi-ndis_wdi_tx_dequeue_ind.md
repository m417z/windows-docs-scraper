# NDIS_WDI_TX_DEQUEUE_IND callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
NdisWdiTxDequeueIndication callback function is called in the context of a [MiniportWdiTxDataSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_data_send) or [MiniportWdiTxTalSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tx_tal_send) by the IHV miniport to dequeue frames from WDI to the IHV miniport.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `Quantum` [in]

The quantum. For more information, see the *Host - target TX transfer scheduling* section in [WDI TX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tx-path).

### `MaxNumFrames` [in]

Maximum frame count.

### `Credit` [in]

Credit value. For more information, see *The target-credit scheme and the pause/resume mechanism* section in [WDI TX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tx-path).

### `ppNBL` [out]

Pointer to a pointer to a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain dequeued by WDI.

## Remarks

A subset of the parameters may not be applicable to a device. For instance, the maximum frame count may not apply to a store and forward device (message-based bus interface).

The following parameters are ignored by TxMgr under these circumstances.

* *Quantum* if set to **WDI_TX_QUANTUM_INVALID** (0xFFFFFFFF)
* *MaxNumFrames* if set to **WDI_TX_MAX_FRAME_COUNT_INVALID** (0xFF)
* *Credit* if set to **WDI_TX_CREDIT_INVALID** (0xFFFF)

The TAL should provide accurate parameters whenever possible to guarantee fairness and avoid overwhelming TIL/target resources.

If the TAL does not have enough credit to dequeue a maximum cost frame, it should issue an [NdisWdiTxSendPauseIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_pause_ind) instead of an *NdisWdiTxDequeueIndication*.

The TxMgr may return a list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) that exceed the limit of the number of frames, frame cost, or quantum. This only happens if the frames are being requeued/replayed after being send completed with status of Postponed and with identical sequence number, which indicates they were originally transmitted as part of a single A-MSDU.

## See also

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisWdiTxDequeueIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_dequeue_ind)

[NdisWdiTxSendPauseIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_pause_ind)

[WDI TX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tx-path)