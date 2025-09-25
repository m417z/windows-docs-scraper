# IOCTL_STORAGE_SET_HOTPLUG_INFO IOCTL

## Description

Sets the hotplug configuration of the specified device. This request takes a [STORAGE_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hotplug_info) structure as input. The **DeviceHotplug** member of the STORAGE_HOTPLUG_INFO structure determines what action is taken. If the value of that member is nonzero, the value for the device's removal policy in the registry is set to **ExpectSurpriseRemoval** and all levels of caching are disabled. If the value of **DeviceHotplug** is zero, the removal policy is set to **ExpectOrderlyRemoval**, and caching might be selectively enabled.

## Parameters

### Major code

### Input buffer

The input buffer.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be greater than or equal to **sizeof**(STORAGE_HOTPLUG_INFO).

### Output buffer

The driver returns the hotplug configuration data in a STORAGE_HOTPLUG_INFO structure in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

The length of a [STORAGE_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hotplug_info) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH if the input buffer is too small. It is set to STATUS_INVALID_PARAMETER_1 if the **Size** member of STORAGE_HOTPLUG_INFO is not the size expected by the class driver for this device. It is set to STATUS_INVALID_PARAMETER_2 if the **MediaRemoveable** member has a value different from that held by the class driver. It is set to STATUS_INVALID_PARAMETER_3 if the **MediaHotplug** member has a value different from that held by the class driver, and it is set to STATUS_INVALID_PARAMETER_5 if the **WriteCacheEnableOverride** member has a value different from that held by the class driver.

## See also

[IOCTL_STORAGE_GET_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_hotplug_info)

[STORAGE_HOTPLUG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hotplug_info)