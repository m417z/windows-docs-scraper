# IOCTL_PAR_QUERY_DEVICE_ID_SIZE IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The IOCTL_PAR_QUERY_DEVICE_ID_SIZE request returns the size, in bytes, of a buffer that can hold a device's IEEE 1284 device ID and a **NULL** terminator.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a [PAR_DEVICE_ID_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_par_device_id_size_information) structure that the client allocates to output the device ID size information. The system-supplied bus driver for parallel ports sets the **DeviceIdSize** member of the output structure to the size, in bytes, of a buffer that can hold the device ID and a **NULL** terminator.

### Output buffer length

The length of a [PAR_DEVICE_ID_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_par_device_id_size_information) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a PAR_DEVICE_ID_SIZE_INFORMATION structure. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the generic status values returned by device control requests for parallel devices or to STATUS_IO_DEVICE_ERROR

## See also

[IOCTL_PAR_QUERY_DEVICE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_device_id)

[PAR_DEVICE_ID_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_par_device_id_size_information)