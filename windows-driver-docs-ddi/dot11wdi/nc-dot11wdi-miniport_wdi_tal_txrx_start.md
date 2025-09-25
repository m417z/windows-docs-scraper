# MINIPORT_WDI_TAL_TXRX_START callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiTalTxRxStart handler function provides TXRX configuration parameters to the TAL. The configuration parameters include the TX/RX capabilities specified by the target device as part of its initialization. It is issued in the context of driver initialization after obtaining device capabilities.

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_TAL_TXRX_START** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `pWifiTxRxConfiguration` [in]

Pointer to the [WDI_TXRX_TARGET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_txrx_target_configuration) structure specified by the target device as part of initialization.

### `pTalTxRxParameters` [out]

Pointer to a [TAL_TXRX_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_tal_txrx_parameters) structure that specifies the TAL parameters used by the TxMgr or RxMgr.

## Return value

**Note** Non-**NDIS_STATUS_SUCCESS** return values indicate a generic failure.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the miniport driver successfully started the datapath components. |

## See also

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[TAL_TXRX_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_tal_txrx_parameters)

[WDI general datapath interfaces](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-general-datapath-interfaces)

[WDI_TXRX_TARGET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_txrx_target_configuration)