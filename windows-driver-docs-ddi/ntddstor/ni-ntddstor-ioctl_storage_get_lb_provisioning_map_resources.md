# IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES IOCTL

## Description

The **IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES** request is sent to the storage class driver to determine available and used mapping resources on a storage device.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The buffer at *Irp->AssociatedIrp.SystemBuffer* contains a [STORAGE_LB_PROVISIONING_MAP_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_lb_provisioning_map_resources) structure.

### Output buffer length

*Parameters.DeviceIoControl.OutputBufferLength* in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be at least **sizeof**(STORAGE_LB_PROVISIONING_MAP_RESOURCES).

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_BUFFER_TOO_SMALL, STATUS_BUFFER_OVERFLOW, or some other error status.

## Remarks

If logical block provisioning is enabled on a LUN, resource mapping counts may be reported from the storage device. Resource mapping information is obtained by using the **IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES** request. A storage monitoring application can use this IOCTL to query resource mapping conditions before a resource threshold or exhaustion event is logged.

## See also

[STORAGE_LB_PROVISIONING_MAP_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_lb_provisioning_map_resources)