# IOCTL_IEEE1284_NEGOTIATE IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_IEEE1284_NEGOTIATE request sets the read and write protocols that are used for a parallel device. This request requires that the parallel port, to which the parallel device is attached, be locked and the parallel device be selected. The system-supplied bus driver for parallel ports negotiates with the parallel device to determine the fastest modes that are supported by both the host chipset and the parallel device from among the modes that are specified by the client. The parallel port bus driver sets the default read and write modes to the negotiated modes.

For more information, see [Setting and Clearing a Communication Mode for a Parallel Device](https://learn.microsoft.com/previous-versions/ff544797(v=vs.85)).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a [PARCLASS_NEGOTIATION_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_parclass_negotiation_mask) structure that the client allocates for the input and output of mode information. The client sets the **usReadMask** and **usWriteMask** members.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member is set to the size, in bytes, of a PARCLASS_NEGOTIATION_MASK structure.

### Output buffer

The **AssociatedIrp.SystemBuffer** points to the PARCLASS_NEGOTIATION_MASK structure that the system-supplied bus driver for parallel ports uses to output mode information. The parallel port bus driver sets the **usReadMask** and **usWriteMask** members to the negotiated modes.

### Output buffer length

The length of a [PARCLASS_NEGOTIATION_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_parclass_negotiation_mask) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If request is successful, the **Information** member is set to the size, in bytes, of a PARCLASS_NEGOTIATION_MASK structure. Otherwise the **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to the following value:

**STATUS_INVALID_PARAMETER**

The value of the **Parameters.DeviceIoControl.InputBufferLength** member is less than the size, in bytes, of a PARCLASS_NEGOTIATION_MASK.

## See also

[PARCLASS_NEGOTIATION_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_parclass_negotiation_mask)

[IOCTL_PAR_GET_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_device_caps)

[IOCTL_PAR_GET_DEFAULT_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_default_modes)

[IOCTL_IEEE1284_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_get_mode)