# _NDIS_WDI_INIT_PARAMETERS structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The NDIS_WDI_INIT_PARAMETERS structure specifies the WDI functions provided by the operating system and called by the IHV WDI driver.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_WDI_INIT_PARAMETERS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_WDI_INIT_PARAMETERS.

To indicate the version of the NDIS_WDI_INIT_PARAMETERS structure, set the
**Revision** member to the following value:

#### NDIS_OBJECT_TYPE_WDI_INIT_PARAMETERS_REVISION_1

Set the
**Size** member to NDIS_SIZEOF_WDI_INIT_PARAMETERS_REVISION_1.

### `WdiVersion`

The version of WDI used by the driver. Set this member to one of the following values:

#### WDI_VERSION_1_0

WDI version 1.0

### `OpenAdapterCompleteHandler`

The entry point of the [NdisWdiOpenAdapterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_open_adapter_complete) callback function.

### `CloseAdapterCompleteHandler`

The entry point of the [NdisWdiCloseAdapterComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_close_adapter_complete) callback function.

### `UeIdleNotificationConfirm`

The entry point of the [NdisWdiIdleNotificationConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_idle_notification_confirm) callback function.

### `UeIdleNotificationComplete`

The entry point of the [NdisWdiIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_idle_notification_complete) callback function.