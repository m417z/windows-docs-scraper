# MINIPORT_WDI_TAL_TXRX_ADD_PORT callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
MiniportWdiTalTxRxAddPort handler function notifies the datapath components of the creation of a new virtual port. It is invoked after the completion of the [OID_WDI_TASK_CREATE_PORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wdi-task-create-port) command and specifies the PortID designated by the target for the port.

It also specifies the default operation mode for the port.

This is a WDI miniport handler inside [NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers).

**Note** You must declare the function by using the **MINIPORT_WDI_TAL_TXRX_ADD_PORT** type. For more
information, see the following Examples section.

## Parameters

### `MiniportTalTxRxContext` [in]

TAL device handle returned by the IHV miniport in [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize).

### `PortId` [in]

Port ID designated by the target for the port.

### `OpMode` [in]

Default operation mode for the port.

## See also

[NDIS_MINIPORT_WDI_DATA_HANDLERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_wdi_data_handlers)

[OID_WDI_TASK_CREATE_PORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wdi-task-create-port)

[TAL_TXRX_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/tal-txrx-handle)

[WDI general datapath interfaces](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-general-datapath-interfaces)

[WDI_OPERATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-_wdi_operation_mode)

[WDI_PORT_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-port-id)