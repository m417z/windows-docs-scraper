# NDIS_WDI_TX_TRANSFER_COMPLETE_IND callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NdisWdiTxTransferCompleteIndication callback function specifies a list of frame buffers that have been transferred to the target.
Frames with different TX Status values are completed in separate indications.

If the TX status is a failure code, an [NdisWdiTxSendCompleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_complete_ind) is not indicated for any of the frames in the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) (NBL) chain.

This is a callback inside [NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api).

## Parameters

### `NdisMiniportDataPathHandle` [in]

The NdisMiniportDataPathHandle passed to the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `WifiTxFrameStatus` [in]

The TX status, specified as a [WDI_TX_FRAME_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_frame_status) value.

### `pNBL` [in]

The null-terminated list of frame buffers that have been transferred to the target.

## See also

[NDIS_WDI_DATA_API](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_data_api)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisWdiTxSendCompleteIndication](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_tx_send_complete_ind)

[WDI_TX_FRAME_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_tx_frame_status)