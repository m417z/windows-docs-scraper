# MINIPORT_WDI_IDLE_NOTIFICATION callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

NDIS calls the MiniportWdiIdleNotification handler function to start the NDIS selective suspend operation on an idle network adapter. Through this operation, the network adapter is suspended and transitioned to a low-power state.

This is a WDI miniport handler inside [NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics).

> [!Note]
> You must declare the function by using the **MINIPORT_WDI_IDLE_NOTIFICATION** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

The handle to the context area that the miniport driver allocated.

### `ForceIdle` [in]

A BOOLEAN value that, when set to TRUE, specifies that the miniport driver must not veto the idle notification and must continue with the low-power state transition.

For more information about the ForceIdle parameter, see the Remarks section.

## Return value

MiniportWdiIdleNotification can return any of the following return values.

|Return code|Description|
|--- |--- |
|**NDIS_STATUS_PENDING**|The miniport driver successfully handled the idle notification. The notification is left in a pending state until the miniport driver calls [NdisWdiIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_idle_notification_complete). **Note:** The miniport driver must not return NDIS_STATUS_SUCCESS from MiniportWdiIdleNotification.|
|**NDIS_STATUS_BUSY**|The miniport driver vetoed the idle notification because the network adapter is still being used. **Note:** MiniportWdiIdleNotification must not return this status code if the _ForceIdle_ parameter is set to **TRUE**.|
|**NDIS_STATUS_FAILURE**|The miniport driver could not issue a bus-specific IRP successfully.|

## See also

[NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics)

[NdisWdiIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-ndis_wdi_idle_notification_complete)