# MINIPORT_WDI_TAL_TXRX_RESET_PORT callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiTalTxRxResetPort handler function is invoked before a dot11 reset task is issued to the target. The functional components RXEngine/TxEngine have already stopped operations associated with this port and any pending data frames have been completed/returned. It allows the TX/RX components to clear the port state. This does not involve changing the operation mode.

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_TAL_TXRX_RESET_PORT** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

Port ID for the port being reset.

## See also

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI general datapath interfaces](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-general-datapath-interfaces)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)