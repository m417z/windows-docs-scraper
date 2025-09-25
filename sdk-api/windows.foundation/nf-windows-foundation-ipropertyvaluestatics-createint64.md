# IPropertyValueStatics::CreateInt64 (windows.foundation.h)

## Description

Creates a new [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object that contains the specified signed 64-bit integer value.

## Parameters

### `value` [in]

Type: **INT64**

The signed 64-bit integer value to store.

### `propertyValue` [out, retval]

Type: **[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)****

A pointer to a new object that contains *value*. Use the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to get the [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) interface for the object.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property value was created successfully. |
| **E_POINTER** | *value* is **NULL**. |
| **E_OUTOFMEMORY** | The [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object could not be created. |

## Remarks

Use the **CreateInt64** method to store a value in an [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object. You can add the **IPropertyValue** object to a property store. Use the [GetInt64](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nf-windows-foundation-ipropertyvalue-getint64) method to retrieve the value from the **IPropertyValue** object.

## See also

[IPropertyValue::GetInt64](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nf-windows-foundation-ipropertyvalue-getint64)

[IPropertyValueStatics](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvaluestatics)