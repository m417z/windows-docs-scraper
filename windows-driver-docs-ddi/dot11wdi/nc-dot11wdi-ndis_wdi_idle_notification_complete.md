# NDIS_WDI_IDLE_NOTIFICATION_COMPLETE callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

Miniport drivers call NdisWdiIdleNotificationComplete callback function to complete a pending idle notification for an NDIS selective suspend operation. NDIS begins the operation when it calls the driver's [MiniportWdiIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_idle_notification) handler function.

This is a control path callback inside [NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters).

## Parameters

### `MiniportAdapterHandle` [in]

The miniport handle.

## See also

[Completing the NDIS Selective Suspend Idle Notification](https://learn.microsoft.com/windows-hardware/drivers/network/completing-the-ndis-selective-suspend-idle-notification)

[MiniportWdiIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_idle_notification)

[NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters)