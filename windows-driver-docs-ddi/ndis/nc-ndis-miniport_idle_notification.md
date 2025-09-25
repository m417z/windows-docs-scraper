# MINIPORT_IDLE_NOTIFICATION callback function

## Description

NDIS calls the *MiniportIdleNotification* handler function to start the NDIS selective suspend operation on an idle network adapter. Through this operation, the network adapter is suspended and transitioned to a low-power state.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function. The miniport driver uses this context area to maintain state information for a network adapter.

### `ForceIdle` [in]

A **BOOLEAN** value that, when set to **TRUE**, specifies that the miniport driver must not veto the idle notification and must continue with the low-power state transition.

For more information about the *ForceIdle* parameter, see the Remarks section.

## Return value

*MiniportIdleNotification* returns one of the following status values:

|Return code|Description|
|--- |--- |
|**NDIS_STATUS_PENDING**|The miniport driver successfully handled the idle notification. The notification is left in a pending state until the miniport driver calls [NdisMIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationcomplete). **Note:** The miniport driver must not return NDIS_STATUS_SUCCESS from MiniportIdleNotification.|
|**NDIS_STATUS_BUSY**|The miniport driver vetoed the idle notification because the network adapter is still being used. **Note:** MiniportIdleNotification must not return this status code if the _ForceIdle_ parameter is set to **TRUE**.|
|**NDIS_STATUS_FAILURE**|The miniport driver could not issue a bus-specific IRP successfully.|

## Remarks

The *MiniportIdleNotification* handler function is required for miniport drivers that support the NDIS selective suspend interface. For more information about how the driver registers its selective suspend handler functions, see [Registering NDIS Selective Suspend Handler Functions](https://learn.microsoft.com/windows-hardware/drivers/network/registering-ndis-selective-suspend-handler-functions).

NDIS sets the *ForceIdle* parameter to **FALSE** when the network adapter has been inactive for longer than the idle time-out period. Therefore, NDIS *selectively suspends* only the network adapter.

The duration of the idle time-out period is specified by the value of the ***SSIdleTimeout** INF keyword. For more information about this keyword, see [Standardized INF Keywords for NDIS Selective Suspend](https://learn.microsoft.com/windows-hardware/drivers/network/standardized-inf-keywords-for-ndis-selective-suspend).

> [!NOTE]
> NDIS sets the *ForceIdle* parameter to **TRUE** only when a system that is compliant with the Always On Always Connected (AOAC) technology is transitioning to a Connected Standby state.

If the miniport driver determines that the network adapter is being used, it can veto the idle notification request by returning NDIS_STATUS_BUSY. This causes NDIS to restart the monitor of activity on the network adapter.

If the adapter becomes inactive again within the idle time-out period, NDIS calls *MiniportIdleNotification*.

> [!NOTE]
> The miniport driver must not return NDIS_STATUS_BUSY if the *ForceIdle* parameter is set to **TRUE**.

After the idle notification is issued, it can be canceled and completed in the following way:

* NDIS can cancel the outstanding idle notification if the following conditions are true:
  * An overlying protocol or filter driver issues either a send packet request or an OID request to the miniport driver.
  * The underlying adapter signals a wake-up event, such as receiving a packet that matches a wake-on-LAN (WOL) pattern or detecting a change in its media connection status.

 NDIS cancels the idle notification by calling [MiniportCancelIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_idle_notification). When this handler function is called, the miniport driver cancels any bus-specific IRPs that it may have previously issued for the idle notification. Finally, the miniport driver calls [NdisMIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationcomplete) to complete the idle notification.

* After the network adapter is in a low-power state, the miniport driver can complete the idle notification itself in order to resume the adapter to a full-power state. The reasons for doing this are specific to the design and requirements of the driver and adapter.

 The miniport driver completes the idle notification by calling [NdisMIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationcomplete). For more information about how the miniport driver completes the idle notification, see [Completing the NDIS Selective Suspend Idle Notification](https://learn.microsoft.com/windows-hardware/drivers/network/completing-the-ndis-selective-suspend-idle-notification).

For more information on how to handle idle notifications for NDIS selective suspend, see [Handling the NDIS Selective Suspend Idle Notification](https://learn.microsoft.com/windows-hardware/drivers/network/handling-the-ndis-selective-suspend-idle-notification).

For guidelines on how to implement the *MiniportIdleNotification* handler function, see [Implementing a MiniportIdleNotification Handler Function](https://learn.microsoft.com/windows-hardware/drivers/network/implementing-a-miniportidlenotification-handler-function).

## See also

[MiniportCancelIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_idle_notification)

[NdisMIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationcomplete)