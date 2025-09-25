# SerCxGetWaitMask function

## Description

The **SerCxGetWaitMask** method returns the event wait mask for the wait operation that is currently pending.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

## Return value

**SerCxGetWaitMask** returns a wait mask that specifies the events that a client (application or peripheral driver) selected to trigger completion of the wait operation that is currently pending. If no wait operation is pending, this method returns the null wait mask, 0x0000. For more information, see the following Remarks section.

## Remarks

The serial controller driver calls **SerCxGetWaitMask** to obtain the wait mask to use for a pending wait operation. Typically, the controller driver calls this method from the [EvtSerCxWaitmask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_waitmask) callback function.

The wait mask indicates the types of events that can trigger completion of a wait operation. Each bit in the wait mask represents a particular type of event. A bit is set in the wait mask if the corresponding event will trigger completion of a wait operation. For more information about the meaning of the bits in the wait mask, see [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports).

## See also

[EvtSerCxWaitmask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_waitmask)

[IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask)

[SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports)