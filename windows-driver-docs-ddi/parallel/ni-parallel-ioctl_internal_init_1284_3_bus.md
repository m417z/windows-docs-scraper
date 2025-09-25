# IOCTL_INTERNAL_INIT_1284_3_BUS IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The **IOCTL_INTERNAL_INIT_1284_3_BUS** request initializes and assigns an IEEE 1284.3 device ID to all the 1284.3 daisy chain devices that are attached to a parallel port.

Windows 2000 supports from zero to four daisy chain devices and an end-of-chain device simultaneously attached to a parallel port. Windows XP supports from zero to two daisy chain devices and an end-of-chain device simultaneously attached to a parallel port.

**Note** This request is included primarily for test purposes, and Microsoft does not recommend using it during the normal operation of a parallel port.

For more information, see [Device Stacks for ParallelPorts and Devices](https://learn.microsoft.com/previous-versions/ff543949(v=vs.85)).

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

The **Status** member is set to one of the generic status values returned by internal device control requests for parallel ports.

## See also

[IOCTL_INTERNAL_SELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_select_device)

[IOCTL_INTERNAL_DESELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_deselect_device)