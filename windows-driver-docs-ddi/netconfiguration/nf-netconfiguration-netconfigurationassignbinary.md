# NetConfigurationAssignBinary function

## Description

The **NetConfigurationAssignBinary** function writes caller-supplied binary data to a specified value name in the registry.

## Parameters

### `Configuration` [_In_]

A handle to a NETCONFIGURATION object that represents an opened registry key.

### `ValueName` [_In_]

A pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name.

### `Buffer` [__In_reads_bytes_(BufferLength)_]

A pointer to a buffer that contains driver-supplied data.

### `BufferLength` [_In_]

The length, in bytes, of the buffer to which *Buffer* points.

## Return value

This function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

The client driver obtains a handle to a NETCONFIGURATION object by calling [NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration) or [NetConfigurationOpenSubConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/nf-netconfiguration-netconfigurationopensubconfiguration).

If an entry of the same name as *ValueName* already exists under the opened registry key, **NetConfigurationAssignBinary** replaces its current value with the caller-supplied value. Otherwise, **NetConfigurationAssignBinary** adds a new value entry with the given name and supplied value to the registry.

## See also