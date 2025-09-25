# WdfRegistryAssignMemory function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryAssignMemory** method assigns data that is contained in a specified memory buffer to a specified value name in the registry.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name.

### `ValueType` [in]

A value that identifies the data type. For a list of data type values, see the **Type** member of [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information).

### `Memory` [in]

A handle to a framework memory object. This object represents a buffer that contains data that will be assigned to the value name that *ValueName* points to.

### `MemoryOffsets` [in, optional]

A pointer to a driver-supplied [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that identifies a subsection of the buffer that *Memory* specifies. This parameter is optional and can be **NULL**.

## Return value

**WdfRegistryAssignMemory** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryAssignMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignmemory) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_SET_VALUE access. |
| **STATUS_INTEGER_OVERFLOW** | The contents of the [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that the *MemoryOffsets* parameter specified were invalid. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If the value name that the *ValueName* parameter specifies already exists, **WdfRegistryAssignMemory** updates the value's data.

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example creates a framework memory object, loads the object's buffer with fake data, and assigns the buffer's contents to a registry value.

```cpp
PUCHAR pBuffer;
WDFMEMORY memory;
NTSTATUS status;
UCHAR i;
DECLARE_UNICODE_STRING_SIZE(valueName, L"MyValueName");

status = WdfMemoryCreate(
                         WDF_NO_OBJECT_ATTRIBUTES,
                         NonPagedPool,
                         0,
                         MEMORY_LENGTH,
                         &memory,
                         (PVOID*)&pBuffer
                         );
if (NT_SUCCESS(status)) {

    // Fill the buffer with fake data.
    for (i = 1; i <= MEMORY_LENGTH; i++) {
        pBuffer[i-1] = i;
    }

    status = WdfRegistryAssignMemory(
                                     Key,
                                     &valueName,
                                     REG_BINARY,
                                     memory,
                                     NULL
                                     );
}
```

## See also

[KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfRegistryAssignMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignmultistring)

[WdfRegistryAssignString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignstring)

[WdfRegistryAssignULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignulong)

[WdfRegistryAssignUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignunicodestring)

[WdfRegistryAssignValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignvalue)