# WdfRegistryQueryValue function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryQueryValue** method retrieves the data that is currently assigned to a specified registry value.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name.

### `ValueLength` [in]

The length, in bytes, of the buffer that *Value* points to.

### `Value` [out, optional]

A pointer to a driver-allocated buffer that receives the registry value's data. If this pointer is **NULL**, **WdfRegistryQueryValue** retrieves the data length but not the data.

### `ValueLengthQueried` [out, optional]

A pointer to a location that receives the registry value's data length. This pointer is optional and can be **NULL**.

### `ValueType` [out, optional]

A pointer to a location that receives the registry value's data type. For a list of data type values, see the **Type** member of [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information). This pointer is optional and can be **NULL**.

## Return value

**WdfRegistryQueryValue** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryQueryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryvalue) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_QUERY_VALUE, KEY_READ, or KEY_ALL_ACCESS access. |
| **STATUS_BUFFER_OVERFLOW** | The buffer that the *Value* parameter points to is too small, and only partial data has been written to the buffer. |
| **STATUS_BUFFER_OVERFLOW** | The *Value* buffer is too small, and no data has been written to the buffer. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The registry value was not available. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example opens a device's hardware key and retrieves the data that is assigned to the **NumberOfToasters** value, which is stored under the device's hardware key.

```cpp
WCHAR  comPort[FM_COM_PORT_STRING_LENGTH];
ULONG  length;
NTSTATUS  status;
ULONG  length, valueType, value;
DECLARE_CONST_UNICODE_STRING(valueName, L"NumberOfToasters");
WDFKEY  hKey;

status = WdfDeviceOpenRegistryKey(
                                  Device,
                                  PLUGPLAY_REGKEY_DEVICE,
                                  KEY_QUERY_VALUE,
                                  NULL,
                                  &hKey
                                  );
if (!NT_SUCCESS (status)) {
    goto Error;
}
status = WdfRegistryQueryValue(
                               hKey,
                               &valueName,
                               sizeof(ULONG),
                               &value,
                               &length,
                               &valueType
                               );
```

## See also

[KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfDeviceOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceopenregistrykey)

[WdfRegistryQueryMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymemory)

[WdfRegistryQueryMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymultistring)

[WdfRegistryQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerystring)

[WdfRegistryQueryULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryulong)

[WdfRegistryQueryUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryunicodestring)