# _USBFN_EVENT enumeration

## Description

Defines notifications sent to class drivers.

## Constants

### `UsbfnEventMinimum`

The minimum value in this enumeration.

### `UsbfnEventAttach`

VBUS is powered. No action is required.

### `UsbfnEventReset`

USBFN has completed a USB Reset. If previously configured, class drivers should reset their state. Transfer requests will be cancelled.

### `UsbfnEventDetach`

 VBUS is no longer powered.
If previously configured, class drivers should
reset their state. Transfer requests will be cancelled.
The **BusSpeed** field of the notification is set appropriately.

### `UsbfnEventSuspend`

 There have been no SOF packets on the bus for 3ms.
If a class driver wants to issue a remote wake up,
the driver must use [IOCTL_INTERNAL_USBFN_SIGNAL_REMOTE_WAKEUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_signal_remote_wakeup) or [IOCTL_INTERNAL_USBFN_TRANSFER_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_transfer_in).

### `UsbfnEventResume`

USBFN has resumed from suspend to the previous state.

### `UsbfnEventSetupPacket`

 USBFN has received a setup packet with
**bmRequestType.Type** set to BMREQUEST_CLASS and
**bmRequestType.Recipient** set to BMREQUEST_TO_INTERFACE.
USBFN forwarded the setup packet to the class driver
specified in **wIndex.LowByte**.

 The setup packet is available in the **SetupPacket** field of the
event. If the control transfer does not require a data stage,
class drivers should respond with
[IOCTL_INTERNAL_USBFN_CONTROL_STATUS_HANDSHAKE_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_control_status_handshake_out).
If a data stage is required, class drivers should respond with
one or more [IOCTL_INTERNAL_USBFN_TRANSFER_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_transfer_in) or [IOCTL_INTERNAL_USBFN_TRANSFER_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_transfer_out), followed by
[IOCTL_INTERNAL_USBFN_CONTROL_STATUS_HANDSHAKE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_control_status_handshake_in) or **IOCTL_INTERNAL_USBFN_CONTROL_STATUS_HANDSHAKE_OUT** in the opposite
direction.

### `UsbfnEventConfigured`

 USBFN has received a SET_CONFIGURATION setup packet. Transfer
requests from class drivers are now permitted.
The **ConfigurationValue** of the notification is set to **wValue.W**.

### `UsbfnEventUnConfigured`

 USBFN has received a SET_CONFIGURATION setup packet with
**wValue.W** set to 0. If previously configured, class drivers should
reset their state. Transfer requests will be cancelled.

### `UsbfnEventPortType`

Deprecated.

### `UsbfnEventBusTearDown`

Deprecated.

### `UsbfnEventSetInterface`

USBFN has received a SET_INTERFACE setup packet. On receiving this
notification the class driver should query for the new endpoint set
for the interface.

### `UsbfnEventMaximum`

The minimum value in this enumeration.