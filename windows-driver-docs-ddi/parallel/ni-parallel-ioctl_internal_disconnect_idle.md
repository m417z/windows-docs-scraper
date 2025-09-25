# IOCTL_INTERNAL_DISCONNECT_IDLE IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_DISCONNECT_IDLE** request disconnects the IEEE 1284 operating modes that are set for a parallel device. The system-supplied bus driver for parallel ports sets the default operating mode to IEEE 1284-compatible.

For more information, see [Setting and Clearing a Communication Mode for a Parallel Device](https://learn.microsoft.com/previous-versions/ff544797(v=vs.85)).

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by internal device control requests for parallel devices.

## See also

[IOCTL_PAR_GET_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_device_caps)

[IOCTL_PAR_GET_DEFAULT_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_default_modes)

[IOCTL_IEEE1284_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_get_mode)

[IOCTL_IEEE1284_NEGOTIATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_negotiate)