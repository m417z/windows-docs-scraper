# IPropertyValue::GetInt32 (windows.foundation.h)

## Description

Gets the signed 32-bit integer value that is stored in the current [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object.

## Parameters

### `value` [out, retval]

Type: **INT32***

The signed 32-bit integer value.

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

[IPropertyValueStatics::CreateInt32](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nf-windows-foundation-ipropertyvaluestatics-createint32)