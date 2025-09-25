# WdfRegistryAssignULong function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryAssignULong** method assigns a specified unsigned long word value to a specified value name in the registry.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name.

### `Value` [in]

A ULONG value that will be assigned to the value name that *ValueName* specifies.

## Return value

**WdfRegistryAssignULong** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryAssignULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignulong) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_SET_VALUE access. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If the value name that the *ValueName* parameter specifies already exists, **WdfRegistryAssignULong** updates the value's data.

The framework sets the value's data type to REG_DWORD.

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example assigns the constant MY_VALUE to the **ValueName** value, under a specified registry key.

```cpp
UNICODE_STRING valueName;
NTSTATUS status;

RtlInitUnicodeString(
                     &valueName,
                     L"ValueName"
                     );
status = WdfRegistryAssignULong(
                                Key,
                                &valueName,
                                MY_VALUE
                                );
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfRegistryAssignMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignmemory)

[WdfRegistryAssignMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignmultistring)

[WdfRegistryAssignString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignstring)

[WdfRegistryAssignUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignunicodestring)

[WdfRegistryAssignValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignvalue)