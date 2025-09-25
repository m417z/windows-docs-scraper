# NDIS_WDI_TX_SEND_COMPLETE_IND callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NdisWdiTxSendCompleteIndication callback function specifies an array of frame IDs associated with the target's sent frames.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

Frames with different TX status values are completed in separate indications.

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `WifiTxFrameStatus` [in]

The TX status, specified as a [WDI_TX_FRAME_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_frame_status) value.

### `NumCompletedSends` [in]

The number of completed sends.

### `WifiTxFrameIdList` [in]

An array of frame IDs. The size of the array is the value of *NumCompletedSends*.

### `WifiTxCompleteList` [in, optional]

An array of TX completion data. The size of the array is the value of *NumCompletedSends*.

## Remarks

[WDI_TX_COMPLETE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_tx_complete_data) is optional for all status values unless the indicated frames are sent over-the-air and have a status of **WDI_TxFrameStatus_SendPostponed**. In that case, **WDI_TX_COMPLETE_DATA** is required.

A TX completion with a frame with **WDI_TxFrameStatus_SendPostponed** is identical to an [NdisWdiTxSendPauseIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_pause_ind) with **WDI_TX_PAUSE_REASON_PS**.

## See also

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[NdisWdiTxSendPauseIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_pause_ind)

[WDI_TX_COMPLETE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_tx_complete_data)

[WDI_TX_FRAME_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_frame_status)

[WDI_TX_PAUSE_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_pause_reason)