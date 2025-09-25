# IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD IOCTL

## Description

A driver can use **IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD** to set the temperature threshold of a storage device (when supported by the hardware). Use [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to determine if the device supports changing the over and under temperature thresholds.

## Parameters

### Major code

### Input buffer

A [STORAGE_TEMPERATURE_THRESHOLD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_temperature_threshold) structure.

### Input buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**([STORAGE_TEMPERATURE_THRESHOLD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_temperature_threshold)).

### Output buffer

This IOCTL has no output structure.

### Output buffer length

This IOCTL has no output structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to **STATUS_SUCCESS**, or possibly to **STATUS_INSUFFICIENT_RESOURCES**.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)

[STORAGE_TEMPERATURE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_temperature_info)