# IOCTL_IEEE1284_GET_MODE IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_IEEE1284_GET_MODE request returns the IEEE 1284 read and write protocols that are currently set for a parallel device. This request does not require that the parallel port, to which the parallel device is attached, be locked.

For more information, see [Setting and Clearing a Communication Mode for a Parallel Device](https://learn.microsoft.com/previous-versions/ff544797(v=vs.85)).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a PARCLASS_NEGOTIATION_MASK structure that the client allocates to output mode information. The system-supplied bus driver for parallel ports specifies the read (reverse) protocol in the **usReadMask** member and the write (forward) protocol in the **usWriteMask** member.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member is set to the size, in bytes, of a [PARCLASS_NEGOTIATION_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_parclass_negotiation_mask) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a PARCLASS_NEGOTIATION_MASK. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to the following value:

**STATUS_BUFFER_TOO_SMALL**

The value of **Parameters.DeviceIoControl.OutputBufferLength** is less than the size, in bytes, of a PARCLASS_NEGOTIATION_MASK structure.

## See also

[PARCLASS_NEGOTIATION_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_parclass_negotiation_mask)

[IOCTL_PAR_GET_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_device_caps)

[IOCTL_PAR_GET_DEFAULT_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_default_modes)

[IOCTL_IEEE1284_NEGOTIATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_negotiate)