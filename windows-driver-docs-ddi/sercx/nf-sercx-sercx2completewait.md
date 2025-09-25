# SerCx2CompleteWait function

## Description

The **SerCx2CompleteWait** method notifies version 2 of the serial framework extension (SerCx2) that an event in the current wait mask has occurred.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

### `Event` [in]

The type of event that is ending the current wait operation. This parameter is a wait mask value. Each event type corresponds to a particular bit in the wait mask. This bit is set to indicate that the corresponding event has occurred. For more information about the types of events that can be specified by a wait mask, see [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports).

## Remarks

When SerCx2 receives an [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) request from a client, the request handler in SerCx2 calls the [EvtSerCx2SetWaitMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_set_wait_mask) callback function to notify the serial controller driver that the wait mask has changed.

When an event in the new wait mask occurs, the driver calls **SerCx2CompleteWait** to notify SerCx2 of the event. If a previously sent [IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask) request is pending in SerCx2 at the time of the **SerCx2CompleteWait** call, SerCx2 completes this request with an output wait mask that indicates which event occurred. Otherwise, SerCx2 stores the event in its internal event history in anticipation of a future **IOCTL_SERIAL_WAIT_ON_MASK** request.

## See also

[EvtSerCxWaitmask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_waitmask)

[IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask)

[IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask)

[SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports)