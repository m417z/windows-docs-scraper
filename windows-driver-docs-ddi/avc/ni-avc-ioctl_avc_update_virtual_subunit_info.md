# IOCTL_AVC_UPDATE_VIRTUAL_SUBUNIT_INFO IOCTL

## Description

The IOCTL_AVC_UPDATE_VIRTUAL_SUBUNIT_INFO I/O control code controls the enumeration of virtual subunits. It is available to user mode as well as kernel-mode components through the IRP_MJ_DEVICE_CONTROL dispatch. For driver-to-driver communication, it is a METHOD_BUFFERED IOCTL, so set the IRP fields accordingly (IrpStack->Parameters.DeviceIoControl.InputBufferLength and Irp->AssociatedIrp.SystemBuffer).

IOCTL_AVC_UPDATE_VIRTUAL_SUBUNIT_INFO is used to add or remove subunit IDs of a single type. Successive calls with a different ID part of the subunit address cause the number of enumerated IDs to change. Note that *avc.sys* adds or removes the highest IDs only. This is a limitation of the AV/C specification, not the driver implementation.

This IOCTL uses the AVC_SUBUNIT_ADDR_SPEC structure.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If successful, the AV/C protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

Possible other return values include:

| Return Value | Description |
| --- | --- |
| STATUS_INSUFFICIENT_RESOURCES | No buffer was passed, or insufficient resources available to perform a registry query. |
| STATUS_INVALID_BUFFER_SIZE | The buffer passed in Irp->AssociatedIrp.SystemBuffer must be at least as large as sizeof(AVC_SUBUNIT_ADDR_SPEC) which includes a single-byte subunit address, but limited to a 32 byte subunit address. |
| STATUS_INVALID_PARAMETER | The subunit address was specified incorrectly. |
| STATUS_ACCESS_DENIED | The current user has insufficient registry access privileges to make the update persistent. |

## Remarks

Must be called at IRQL = PASSIVE_LEVEL.

## See also

[AVC_SUBUNIT_ADDR_SPEC](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_subunit_addr_spec)

[IOCTL_AVC_BUS_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_bus_reset)

[IOCTL_AVC_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_class)

[IOCTL_AVC_REMOVE_VIRTUAL_SUBUNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_remove_virtual_subunit_info)