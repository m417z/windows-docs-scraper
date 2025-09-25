# IOCTL_STORAGE_GET_HOTPLUG_INFO IOCTL

## Description

Retrieves the hotplug configuration of the specified device.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the hotplug configuration data in a [STORAGE_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hotplug_info) structure in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be greater than or equal to **sizeof**(STORAGE_HOTPLUG_INFO).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to **sizeof**(STORAGE_HOTPLUG_INFO). The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL if the output buffer is too small.

## See also

[IOCTL_STORAGE_SET_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_hotplug_info)

[STORAGE_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hotplug_info)