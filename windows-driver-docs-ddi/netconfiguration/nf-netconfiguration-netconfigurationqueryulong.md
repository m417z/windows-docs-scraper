# NetConfigurationQueryUlong function

## Description

Retrieves the specified unsigned long word (REG_DWORD) data from the adapter configuration object and copies the data to a specified location.

## Parameters

### `Configuration` [_In_]

Handle to a NETCONFIGURATION object that represents an opened registry key.

### `Flags` [_In_]

A valid bitwise OR of [NET_CONFIGURATION_QUERY_ULONG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/ne-netconfiguration-_net_configuration_query_ulong_flags)-typed flags.

### `ValueName` [_In_]

A pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a name for the ULONG value.

### `Value` [_Out_]

A pointer to a location that receives the data that is assigned to the value that *ValueName* specifies.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

The client driver obtains a handle to a NETCONFIGURATION object by calling [NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration) or [NetConfigurationOpenSubConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/nf-netconfiguration-netconfigurationopensubconfiguration).

## See also