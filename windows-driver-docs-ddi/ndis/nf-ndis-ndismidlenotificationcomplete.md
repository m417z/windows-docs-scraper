# NdisMIdleNotificationComplete function

## Description

Miniport drivers call **NdisMIdleNotificationComplete** to complete a pending idle notification for an NDIS selective suspend operation. NDIS begins the operation when it calls the driver's [MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification) handler function.

## Parameters

### `MiniportAdapterHandle` [in]

The network adapter handle that NDIS passed to the *MiniportAdapterHandle* parameter of [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

## Remarks

NDIS calls the miniport driver's [MiniportCancelIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_idle_notification) handler function to complete a pending idle notification for an NDIS selective suspend operation. Miniport drivers call **NdisMIdleNotificationComplete** to notify NDIS that the idle notification is complete for the network adapter. NDIS then transitions the adapter to a full-power state in order to complete the selective suspend operation.

Before the miniport drivers calls **NdisMIdleNotificationComplete**, it must cancel any bus-specific I/O request packets (IRPs) that it may have previously issued for the idle notification.

For example, when NDIS calls the [MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification) function, the USB miniport driver issues the bus-specific USB idle request IRP ([IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_submit_idle_notification)) to the USB bus driver. When NDIS calls the driver's [MiniportCancelIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_idle_notification) function, the driver cancels the IRP. When the USB bus driver calls the completion routine that is associated with the IRP, it confirms that the IRP is cancelled and the device can resume to a full-power state. In the context of the completion routine, the miniport driver calls **NdisMIdleNotificationComplete**. For more information, see [Implementing a USB Idle Request IRP Completion Routine](https://learn.microsoft.com/windows-hardware/drivers/network/implementing-a-usb-idle-request-irp-completion-routine).

For more information on how miniport drivers complete NDIS selective suspend idle notifications, see [Completing the NDIS Selective Suspend Idle Notification](https://learn.microsoft.com/windows-hardware/drivers/network/completing-the-ndis-selective-suspend-idle-notification).

**Note** A miniport driver must not call [NdisMIdleNotificationConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationconfirm) for a previously completed idle notification.

## See also

[IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_submit_idle_notification)

[MiniportCancelIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_idle_notification)

[MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification)

[NdisMIdleNotificationConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationconfirm)