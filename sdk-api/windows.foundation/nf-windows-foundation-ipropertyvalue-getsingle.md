# IPropertyValue::GetSingle (windows.foundation.h)

## Description

Gets the 32-bit floating point value that is stored in the current [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object.

## Parameters

### `value` [out, retval]

Type: **FLOAT***

The 32-bit floating point value.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property value was returned successfully. |
| **E_POINTER** | *value* is **NULL**. |
| **E_INCORRECT_TYPE** | The type of *value* does not match the [Type](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nf-windows-foundation-ipropertyvalue-get_type) property. |

## See also

[IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue)

[IPropertyValueStatics::CreateSingle](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nf-windows-foundation-ipropertyvaluestatics-createsingle)