# IOCTL_AVC_BUS_RESET IOCTL

## Description

The IOCTL_AVC_BUS_RESET I/O control code allows the caller to complete any previous IOCTL_AVC_UPDATE_VIRTUAL_SUBUNIT_INFO and IOCTL_AVC_REMOVE_VIRTUAL_SUBUNIT_INFO control requests that did not use the AVC_SUBUNIT_ADDR_TRIGGERBUSRESET flag. It is available to user mode as well as kernel-mode components through the IRP_MJ_DEVICE_CONTROL dispatch.

For driver-to-driver communication, it is a METHOD_BUFFERED IOCTL, so set the IRP fields accordingly (IrpStack->Parameters.DeviceIoControl.InputBufferLength and Irp->AssociatedIrp.SystemBuffer). This request does not require any additional parameters, so the input and output buffers should be set to **NULL**.

This request causes *avc.sys* to invalidate its device relations, which results in the PnP manager asking for an updated list of child device objects (virtual subunits). If there are no new or removed child device objects, no action will be taken. If there are new or removed child device objects, their drivers will be loaded or unloaded, and a 1394 bus reset will be triggered for each PDO as each is started or removed.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Must be called at IRQL = PASSIVE_LEVEL

## See also

[AVC_SUBUNIT_ADDR_SPEC](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_subunit_addr_spec)

[IOCTL_AVC_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_class)

[IOCTL_AVC_REMOVE_VIRTUAL_SUBUNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_remove_virtual_subunit_info)

[IOCTL_AVC_UPDATE_VIRTUAL_SUBUNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_update_virtual_subunit_info)