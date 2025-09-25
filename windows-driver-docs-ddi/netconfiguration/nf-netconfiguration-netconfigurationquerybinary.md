# NetConfigurationQueryBinary function

## Description

Retrieves the data that is currently assigned to a specified registry value, stores the data in a framework-allocated buffer, and creates a framework memory object to represent the buffer.

## Parameters

### `Configuration` [_In_]

A handle to a NETCONFIGURATION object that represents an opened registry key.

### `ValueName` [_In_]

A pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name.

### `PoolType` [_In_]

A [**POOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-typed value that specifies the type of memory to be allocated for the data buffer.

### `MemoryAttributes` [_In_opt_]

A pointer to a [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains object attributes for the new memory object. This parameter is optional and can be **WDF_NO_OBJECT_ATTRIBUTES**.

### `Memory` [_Out_]

A pointer to a location that receives a handle to the new memory object. The framework allocates this memory buffer and automatically frees it when the NETCONFIGURATION object is closed.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

The client driver obtains a handle to a NETCONFIGURATION object by calling [NetAdapterOpenConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteropenconfiguration) or [NetConfigurationOpenSubConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/netconfiguration/nf-netconfiguration-netconfigurationopensubconfiguration).

The memory allocated by this function is automatically freed by the framework when the NETCONFIGURATION object is closed.

## See also