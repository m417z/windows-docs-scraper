# NDIS_WDI_IDLE_NOTIFICATION_CONFIRM callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

Miniport drivers call NdisWdiIdleNotificationConfirm callback function to notify NDIS that the idle network adapter can safely be suspended and transitioned to a low-power state. Miniport drivers call this function during an NDIS selective suspend operation. NDIS begins the operation when it calls the driver's [MiniportWdiIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_idle_notification) handler function.

This is a control path callback inside [NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters).

## Parameters

### `MiniportAdapterHandle` [in]

The miniport handle.

### `DeviceIdlePowerState` [in]

An [NDIS_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_device_power_state) enumeration value that specifies the lowest power state that the network adapter supports for a low-power state transition.

**Note** For USB network adapters, this parameter must be **NdisDeviceStateD2**.

## See also

[Handling the NDIS Selective Suspend Idle Notification](https://learn.microsoft.com/windows-hardware/drivers/network/handling-the-ndis-selective-suspend-idle-notification)

[NDIS_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_device_power_state)

[NDIS_WDI_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_wdi_init_parameters)