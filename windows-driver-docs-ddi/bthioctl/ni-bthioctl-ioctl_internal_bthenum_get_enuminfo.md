# IOCTL_INTERNAL_BTHENUM_GET_ENUMINFO IOCTL

## Description

The IOCTL_INTERNAL_BTHENUM_GET_ENUMINFO request obtains information about the underlying device and
service that caused the Plug and Play (PnP) manager to load the profile driver.

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
[BTH_ENUMERATOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_bth_enumerator_info) structure that
contains information about the enumeration's type and action, as well as information about the remote
device.

### Output buffer length

The length of a
[BTH_ENUMERATOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_bth_enumerator_info) structure.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[BTH_ENUMERATOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_bth_enumerator_info)