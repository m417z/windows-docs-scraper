# IOCTL_SERIAL_WAIT_ON_MASK IOCTL

## Description

The **IOCTL_SERIAL_WAIT_ON_MASK** request is used to wait for the occurrence of any wait event specified by using an [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) request.

A wait-on-mask request is completed after one of the following events occurs:

* A wait event occurs that was specified by the most recent set-wait-mask request.
* An **IOCTL_SERIAL_SET_WAIT_MASK** request is received while a wait-on-mask request is pending. The driver completes the pending wait-on-mask request with a status of STATUS_SUCCESS and the output wait mask is set to zero.

A client can wait for the wait events represented by flag bits **SERIAL_EV_RXCHAR** through **SERIAL_EV_EVENT2**. For more information about these event flags, see [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports).

A client sends an **IOCTL_SERIAL_WAIT_ON_MASK** request to wait for the occurrence of an event that was specified in the wait mask supplied by the most recent **IOCTL_SERIAL_SET_WAIT_MASK** request. If one or more events in the current wait mask occur before the **IOCTL_SERIAL_WAIT_ON_MASK** request is sent, this request is immediately completed with a status of STATUS_SUCCESS and an output mask value that identifies the events. If no event in the wait mask occurs before the **IOCTL_SERIAL_WAIT_ON_MASK** request is sent, this request is marked as pending, and it waits in the serial controller queue for the next occurrence of an event in the current wait mask.

After a client's **IOCTL_SERIAL_WAIT_ON_MASK** request is completed with a status of STATUS_SUCCESS and a nonzero output mask value, the client can send a new **IOCTL_SERIAL_WAIT_ON_MASK** request to wait for another event in the current wait mask. Only a new event that occurs after the previous **IOCTL_SERIAL_WAIT_ON_MASK** request was completed will cause the new **IOCTL_SERIAL_WAIT_ON_MASK** request to be completed with a status of STATUS_SUCCESS and a nonzero output mask value.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

**AssociatedIrp.System** buffer points to a ULONG buffer that holds an event wait mask. The event wait mask indicates which wait events occurred. The event wait mask is set to zero or to the bitwise-OR of one or more of the [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports) flag bits.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a ULONG.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the size, in bytes, of a ULONG.

The **Status** member is set to one of the [Generic Status Values for Serial Device Control Requests](https://learn.microsoft.com/windows-hardware/drivers/serports/serial-device-control-requests2). A status of STATUS_INVALID_PARAMETER indicates that no wait events are set, or a wait-on-mask request is already pending.

## See also

[IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask)

[SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports)