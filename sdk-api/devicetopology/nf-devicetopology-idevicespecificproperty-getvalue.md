# IDeviceSpecificProperty::GetValue

## Description

The **GetValue** method gets the current value of the device-specific property.

## Parameters

### `pvValue` [out]

Pointer to a caller-allocated buffer into which the method writes the property value.

### `pcbValue`

[inout] Pointer to a **DWORD** variable that specifies the size in bytes of the property value. On entry, **pcbValue* contains the size of the caller-allocated buffer (or 0 if *pvValue* is **NULL**). Before returning, the method writes the actual size of the property value written to the buffer (or the required size if the buffer is too small or if *pvValue* is **NULL**).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pcbValue* is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer pointed to by parameter *pvValue* is too small to contain the property value, or *pvValue* is **NULL** and the size of the property value is fixed rather than variable. For information about this macro, see the Windows SDK documentation. |

## Remarks

If the size of the property value is variable rather than fixed, the caller can obtain the required buffer size by calling **GetValue** with parameter *pvValue* = **NULL** and **pcbValue* = 0. The method writes the required buffer size to **pcbValue*. With this information, the caller can allocate a buffer of the required size and call **GetValue** a second time to obtain the property value.

If the caller-allocated buffer is too small to hold the property value, **GetValue** writes the required buffer size to **pcbValue* and returns an error status code. In this case, it writes nothing to the buffer pointed by *pvValue*.

## See also

[IDeviceSpecificProperty Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicespecificproperty)