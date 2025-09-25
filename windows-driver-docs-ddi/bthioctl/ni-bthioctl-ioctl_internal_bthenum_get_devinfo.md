# IOCTL_INTERNAL_BTHENUM_GET_DEVINFO IOCTL

## Description

The IOCTL_INTERNAL_BTHENUM_GET_DEVINFO request returns information about the remote device that
caused the Plug and Play (PnP) manager to load the current instance of the profile driver.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer that holds a
[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info) structure that
contains information about the device's state, the device's address, and class of device (CoD).

### Output buffer length

The length of a
[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the output
buffer. Otherwise, the
**Information** member is set to zero.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_INVALID_BUFFER_SIZE | The output buffer was sized incorrectly. |

## See also

[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info)