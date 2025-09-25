# WdfRegistryQueryMemory function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryQueryMemory** method retrieves the data that is currently assigned to a specified registry value, stores the data in a framework-allocated buffer, and creates a framework memory object to represent the buffer.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name.

### `PoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-typed value that specifies the type of memory to be allocated for the data buffer.

### `MemoryAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains object attributes for the new memory object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Memory` [out]

A pointer to a location that receives a handle to the new memory object.

### `ValueType` [out, optional]

A pointer to a location that receives the data type. For a list of data type values, see the **Type** member of [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information). This pointer is optional and can be **NULL**.

## Return value

**WdfRegistryQueryMemory** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryQueryMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymemory) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory object could not be allocated. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_QUERY_VALUE, KEY_READ, or KEY_ALL_ACCESS access. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The registry value was not available. |
| **STATUS_RESOURCE_DATA_NOT_FOUND** | The registry value exists under the specified key, but is empty. |

For a list of other return values that the **WdfRegistryQueryMemory** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

When a driver calls **WdfRegistryQueryMemory**, the framework allocates a buffer that is large enough to hold the specified registry value's data. After **WdfRegistryQueryMemory** returns, the driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer) to obtain a pointer to the buffer and the buffer's size.

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example retrieves the data that is assigned to the **MyValueName** value and then obtains the data's address and size.

```cpp
WDFMEMORY memory;
size_t size;
PUCHAR pBuf;
NTSTATUS status;
ULONG type;
DECLARE_CONST_UNICODE_STRING(valueName1, L"MyValueName");

status = WdfRegistryQueryMemory(
                                Key,
                                &valueName1,
                                PagedPool,
                                NULL,
                                &memory,
                                &type
                                );
pBuf = (PUCHAR)WdfMemoryGetBuffer(
                                   memory,
                                   &size
                                   );
```

## See also

[KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)

[WdfRegistryQueryMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymultistring)

[WdfRegistryQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerystring)

[WdfRegistryQueryULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryulong)

[WdfRegistryQueryUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryunicodestring)

[WdfRegistryQueryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryvalue)