# NdisMIdleNotificationConfirm function

## Description

Miniport drivers call **NdisMIdleNotificationConfirm** to notify NDIS that the idle network adapter can safely be suspended and transitioned to a low-power state.

Miniport drivers call this function during an NDIS selective suspend operation. NDIS begins the operation when it calls the driver's [MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification) handler function.

## Parameters

### `MiniportAdapterHandle` [in]

The network adapter handle that NDIS passed to the *MiniportAdapterHandle* parameter of [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `IdlePowerState` [in]

An [NDIS_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_device_power_state) enumeration value that specifies the lowest power state that the network adapter supports for a low-power state transition.

**Note** For USB network adapters, this parameter must be **NdisDeviceStateD2**.

## Remarks

Miniport drivers call **NdisMIdleNotificationConfirm** after NDIS calls the driver's [MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification) function. By calling **NdisMIdleNotificationConfirm**, the driver notifies NDIS that the suspend operation can start and the network adapter can be transitioned to a low-power state. In this call, the miniport driver sets the *IdlePowerState* parameter to the lowest power state that the device can transition to.

Before the miniport driver calls **NdisMIdleNotificationConfirm**, it must issue any bus-specific I/O request packets (IRPs) that may be necessary to selectively suspend the network adapter.

For example, when NDIS calls the [MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification) function, the USB miniport driver issues the bus-specific I/O request packet (IRP) for a USB idle request ([IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_submit_idle_notification)) to the USB bus driver. When the USB bus driver confirms that the network adapter can transition to a low-power state, it calls the callback routine associated with the IRP. Within the context of the callback routine, the USB miniport driver calls **NdisMIdleNotificationConfirm**. For more information, see [Implementing a USB Idle Request IRP Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/network/implementing-a-usb-idle-request-irp-callback-routine).

**Note** A miniport driver must not call **NdisMIdleNotificationConfirm** for an idle notification that was previously completed. The miniport driver completes the idle notification by calling [NdisMIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationcomplete).

For more information about how to handle NDIS selective suspend idle notifications, see [Handling the NDIS Selective Suspend Idle Notification](https://learn.microsoft.com/windows-hardware/drivers/network/handling-the-ndis-selective-suspend-idle-notification).

## See also

[IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_submit_idle_notification)

[MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification)

[NdisMIdleNotificationComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationcomplete)