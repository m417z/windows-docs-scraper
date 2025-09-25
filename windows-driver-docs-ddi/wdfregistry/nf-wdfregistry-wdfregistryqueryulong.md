# WdfRegistryQueryULong function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryQueryULong** method retrieves the unsigned long word (REG_DWORD) data that is currently assigned to a specified registry value and copies the data to a specified location.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a name for the registry value.

### `Value` [out]

A pointer to a location that receives the data that is assigned to the registry value that *ValueName* specifies.

## Return value

**WdfRegistryQueryULong** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryQueryULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryulong) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to complete the operation. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_QUERY_VALUE, KEY_READ, or KEY_ALL_ACCESS access. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The data type of the registry value that the *ValueName* parameter specified was not REG_DWORD. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The registry value was not available. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about registry-key objects, see [Using the Registry in WDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example retrieves the data that is currently assigned to the **NumberOfThings** value.

```cpp
NTSTATUS  status;
ULONG  value;
DECLARE_CONST_UNICODE_STRING(valueName, L"NumberOfThings");

status = WdfRegistryQueryULong(
                               hKey,
                               &valueName,
                               &value
                               );
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfRegistryQueryMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymemory)

[WdfRegistryQueryMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymultistring)

[WdfRegistryQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerystring)

[WdfRegistryQueryUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryunicodestring)

[WdfRegistryQueryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryvalue)