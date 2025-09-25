# WdfRegistryAssignUnicodeString function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryAssignUnicodeString** method assigns a specified Unicode string to a specified value name in the registry.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name.

### `Value` [in]

A pointer to a UNICODE_STRING structure that contains the string to be assigned to the value name that *ValueName* specifies.

## Return value

**WdfRegistryAssignUnicodeString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryAssignUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignunicodestring) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_SET_VALUE access. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to complete the operation. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If the string that the *Value* parameter specifies is not NULL-terminated, the framework adds a NULL character when copying the string to the registry.

If the value name that the *ValueName* parameter specifies already exists, **WdfRegistryAssignUnicodeString** updates the value's data.

The framework sets the value's data type to REG_SZ.

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example assigns a Unicode string "String1" to the **ValueName** value, under a specified registry key.

```cpp
UNICODE_STRING ustring1, valueName;
NTSTATUS status;

RtlInitUnicodeString(
                     &ustring1,
                     L"String1"
                     );
RtlInitUnicodeString(
                     &valueName,
                     L"ValueName"
                     );

status = WdfRegistryAssignUnicodeString(
                                        Key,
                                        &valueName,
                                        &string1
                                        );
```

## See also

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfRegistryAssignMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignmemory)

[WdfRegistryAssignMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignmultistring)

[WdfRegistryAssignString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignstring)

[WdfRegistryAssignULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignulong)

[WdfRegistryAssignValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignvalue)