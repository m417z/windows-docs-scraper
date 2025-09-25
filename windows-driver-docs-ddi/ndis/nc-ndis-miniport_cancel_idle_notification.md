# MINIPORT_CANCEL_IDLE_NOTIFICATION callback function

## Description

NDIS calls the *MiniportCancelIdleNotification* handler function to notify the miniport driver that NDIS has detected activity on the suspended network adapter. Because of this, NDIS cancels the idle notification so that the network adapter can be transitioned to a full-power state.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function. The miniport driver uses this context area to maintain state information for a network adapter.

## Remarks

The *MiniportCancelIdleNotification* handler function is required for miniport drivers that support the NDIS selective suspend interface. For more information about how the driver registers its selective suspend handler functions, see [Registering NDIS Selective Suspend Handler Functions](https://learn.microsoft.com/windows-hardware/drivers/network/registering-ndis-selective-suspend-handler-functions).

NDIS calls the miniport driver's [MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification) handler function to start an NDIS selective suspend operation on an idle network adapter. After the network adapter has been suspended and transitioned to a low-power state, NDIS can cancel the outstanding idle notification if any of the following conditions are true:

* An overlying protocol or filter driver issues either a send packet request or an OID request to the miniport driver.
* The underlying adapter signals a wake-up event, such as receiving a packet that matches a wake-on-LAN (WOL) pattern or detecting a change in its media connection status.

NDIS cancels the idle notification by calling *MiniportCancelIdleNotification*. When this handler function is called, the miniport driver first cancels any bus-specific I/O request packets (IRPs) that it may have previously issued for the idle notification.
Finally, the miniport driver calls [NdisMIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationcomplete) to complete the idle notification.

For more information about how NDIS cancels the idle notification, see [Canceling the NDIS Selective Suspend Idle Notification](https://learn.microsoft.com/windows-hardware/drivers/network/canceling-the-ndis-selective-suspend-idle-notification).

For guidelines on how to implement the *MiniportCancelIdleNotification* handler function and IRP completion routines, see [Implementing a MiniportCancelIdleNotification Handler Function](https://learn.microsoft.com/windows-hardware/drivers/network/implementing-a-miniportcancelidlenotification-handler-function).

## See also

[IoCancelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocancelirp)

[MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification)

[NdisMIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationcomplete)