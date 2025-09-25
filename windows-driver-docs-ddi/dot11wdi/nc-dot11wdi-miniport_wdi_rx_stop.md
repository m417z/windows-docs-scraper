# MINIPORT_WDI_RX_STOP callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiRxStop handler function stops RX on a given port and accepts the wildcard port ID to stop RX across the adapter. The TAL completes the RX stop operation by completing the request with a success status, or by completing it with a pending status and asynchronously indicating [RxStopConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_rx_stop_confirm).

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

Prior to completing the indication, the target must be configured to stop indicating new traffic on the selected port or the entire adapter.

This request is issued to the TAL as part of a transition to low power (adapter) and dot11 reset (port).

**Note** You must declare the function by using the **MINIPORT_WDI_RX_STOP** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

The port ID.

### `pWifiStatus` [out]

Status from the IHV miniport. A success status indicates that the operation completion synchronously. A pending status indicates that the stop will be asynchronously confirmed.

## See also

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI RX path](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-rx-path)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)