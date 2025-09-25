# WdfRegistryQueryUnicodeString function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryQueryUnicodeString** method retrieves the string data that is currently assigned to a specified registry string value and copies the string to a specified [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a name for the registry value.

### `ValueByteLength` [out, optional]

A pointer to a location that receives the number of bytes that are contained in the Unicode string that *Value* points to, including the terminating **NULL** byte. This pointer is optional and can be **NULL**

### `Value` [in, out]

A pointer to a UNICODE_STRING structure that receives the data string for the key that *Key* specifies. If this parameter is **NULL** and *ValueByteLength* is non-**NULL**, **WdfRegistryQueryUnicodeString** returns only the size of the string.

## Return value

**WdfRegistryQueryUnicodeString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryQueryUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryunicodestring) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to complete the operation. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_QUERY_VALUE, KEY_READ, or KEY_ALL_ACCESS access. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The data type of the registry value that the *ValueName* parameter specified was not REG_SZ. |
| **STATUS_BUFFER_OVERFLOW** | The buffer that the *Value* parameter points to was too small, and only partial data was written to the buffer. |
| **STATUS_BUFFER_OVERFLOW** | The buffer that the *Value* parameter points to was too small, and no data was written to the buffer. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The registry value was not available. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example, which is from the [Serial](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver, retrieves the Unicode string that represents the string data that is assigned to the **PortName** value under a device's hardware key.

```cpp
NTSTATUS
SerialReadSymName(
    IN WDFDEVICE Device,
    __out PWCHAR RegName,
    IN OUT PUSHORT LengthOfRegName // In characters
    )
{
    NTSTATUS status;
    WDFKEY hKey;
    UNICODE_STRING value;
    UNICODE_STRING valueName;
    USHORT requiredLength;

    value.Buffer = RegName;
    value.MaximumLength = *LengthOfRegName;
    value.Length = 0;

    status = WdfDeviceOpenRegistryKey(
                                      Device,
                                      PLUGPLAY_REGKEY_DEVICE,
                                      STANDARD_RIGHTS_ALL,
                                      WDF_NO_OBJECT_ATTRIBUTES,
                                      &hKey
                                      );

    if (NT_SUCCESS (status)) {
        RtlInitUnicodeString(
                             &valueName,
                             L"PortName"
                             );
        status = WdfRegistryQueryUnicodeString (
                                      hKey,
                                      &valueName,
                                      &requiredLength,
                                      &value
                                      );
        WdfRegistryClose(hKey);
    }
    return status;
}
```

## See also

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose)

[WdfRegistryQueryMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymemory)

[WdfRegistryQueryMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymultistring)

[WdfRegistryQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerystring)

[WdfRegistryQueryULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryulong)

[WdfRegistryQueryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryvalue)