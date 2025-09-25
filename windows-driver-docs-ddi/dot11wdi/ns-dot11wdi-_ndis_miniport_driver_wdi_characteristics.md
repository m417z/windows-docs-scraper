# _NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS structure defines the set of handlers that a WDI miniport driver must implement. It is used by the IHV driver to register additional handlers for the control path and the full set of handlers for the data path.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_MINIPORT_WDI_CHARACTERISTICS.

To indicate the version of the NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS structure, set the
**Revision** member to the following value:

#### NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS_REVISION_1

Set the
**Size** member to NDIS_SIZEOF_MINIPORT_WDI_CHARACTERISTICS_REVISION_1.

### `WdiVersion`

The version of WDI used by the driver. Set this member to one of the following values:

#### WDI_VERSION_LATEST

The latest WDI version

#### WDI_VERSION_1_0_1

WDI version 1.0.1

#### WDI_VERSION_1_0

WDI version 1.0

### `AllocateAdapterHandler`

The entry point of the [MiniportWdiAllocateAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_allocate_adapter) handler function.

### `FreeAdapterHandler`

The entry point of the [MiniportWdiFreeAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_free_adapter) handler function.

### `OpenAdapterHandler`

The entry point of the [MiniportWdiOpenAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_open_adapter) handler function.

### `CloseAdapterHandler`

The entry point of the [MiniportWdiCloseAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_close_adapter) handler function.

### `StartOperationHandler`

The entry point of the [MiniportWdiStartOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_start_adapter_operation) handler function.

### `StopOperationHandler`

The entry point of the [MiniportWdiStopOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_stop_adapter_operation) handler function.

### `PostPauseHandler`

The entry point of the [MiniportWdiPostAdapterPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_post_adapter_pause) handler function.

### `PostRestartHandler`

The entry point of the [MiniportWdiPostAdapterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_post_adapter_restart) handler function.

### `HangDiagnoseHandler`

The entry point of the [MiniportWdiAdapterHangDiagnose](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_adapter_hang_diagnose) handler function.

### `TalTxRxInitializeHandler`

The entry point of the [MiniportWdiTalTxRxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_initialize) handler function.

### `TalTxRxDeinitializeHandler`

The entry point of the [MiniportWdiTalTxRxDeinitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_tal_txrx_deinitialize) handler function.

### `LeIdleNotificationHandler`

The entry point of the [MiniportWdiIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_idle_notification) handler function.

### `LeCancelIdleNotificationHandler`

The entry point of the [MiniportWdiCancelIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_cancel_idle_notification) handler function.