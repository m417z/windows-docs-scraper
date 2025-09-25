# WdfRegistryQueryString function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryQueryString** method retrieves the string data that is currently assigned to a specified registry string value and assigns the string to a specified framework string object.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a name for the registry value.

### `String` [in]

A handle to a framework string object. The framework will assign the registry value's string data to this object.

## Return value

**WdfRegistryQueryString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerystring) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to complete the operation. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_QUERY_VALUE, KEY_READ, or KEY_ALL_ACCESS access. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The data type of the registry value that the *ValueName* parameter specified was not REG_SZ. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The registry value was not available. |
| **STATUS_RESOURCE_DATA_NOT_FOUND** | The registry value exists under the specified key, but is empty. |

For a list of other return values that the **WdfRegistryQueryString** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

To obtain a string from a string object, your driver can call [WdfStringGetUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringgetunicodestring).

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example creates a string object, retrieves string data from a registry key, and obtains the string data from the string object.

```cpp
UNICODE_STRING str;
WDFSTRING string;
NTSTATUS status;
DECLARE_CONST_UNICODE_STRING(valueName, STRING_VALUE_NAME);

status = WdfStringCreate(
                         NULL,
                         WDF_NO_OBJECT_ATTRIBUTES,
                         &string
                         );
if (NT_SUCCESS(status)) {
    status = WdfRegistryQueryString(
                                    Key,
                                    &valueName,
                                    string
                                    );
    if (NT_SUCCESS(status)) {
        WdfStringGetUnicodeString(
                                  string,
                                  &str
                                  );
    }
}
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfRegistryQueryMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymemory)

[WdfRegistryQueryMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymultistring)

[WdfRegistryQueryULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryulong)

[WdfRegistryQueryUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryunicodestring)

[WdfRegistryQueryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryvalue)

[WdfStringCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringcreate)

[WdfStringGetUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringgetunicodestring)