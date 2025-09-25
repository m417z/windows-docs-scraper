# MINIPORT_WDI_RX_PPDU_RSSI callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiRxPpduRssi handler function returns the absolute value of RSSI (in dB) for the PPDU. The RxMgr may request the RSSI only once per data indication using the PNET_BUFFER_LIST obtained from [MiniportWdiRxGetMpdus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_rx_get_mpdus).

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_RX_PPDU_RSSI** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `pNBL` [in]

Pointer to the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) for which the RSSI is requested.

### `pRssi` [out]

The absolute value of RSSI, in dB.

## See also

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI RX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-rx-path)