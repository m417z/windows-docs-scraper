# SerCxCompleteWait function

## Description

The **SerCxCompleteWait** method notifies the serial framework extension (SerCx) that an event in the current wait mask has occurred.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `Event` [in]

The type of event that is ending the current wait operation. This parameter is a wait mask value. Each event type corresponds to a particular bit in the wait mask. This bit is set to indicate that the corresponding event has occurred. For more information about the types of events that can be specified by a wait mask, see [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports).

## Return value

**SerCxCompleteWait** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status code.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The specified event is not included in the current wait mask. |

## Remarks

When SerCx receives an [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) request from a client, the request handler in SerCx calls the [EvtSerCxWaitmask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_waitmask) callback function to notify the serial controller driver that the wait mask has changed. The wait mask specifies a set of hardware events for the serial controller to monitor. During this call, the driver discards any old wait mask that might have been specified in a previous *EvtSerCxWaitmask* call, and then configures the serial controller hardware to detect the events in the new wait mask.

Later, when an event in the new wait mask occurs, the driver calls **SerCxCompleteWait** to notify SerCx of the event. If a previously sent [IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask) request is pending, **SerCxCompleteWait** completes this request with a status of STATUS_SUCCESS and an output wait mask that indicates which event occurred. Otherwise, **SerCxCompleteWait** stores the event in its internal event history in anticipation of a future **IOCTL_SERIAL_WAIT_ON_MASK** request.

## See also

[EvtSerCxWaitmask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_waitmask)

[IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask)

[IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask)

[SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports)

[SerCxGetWaitMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetwaitmask)