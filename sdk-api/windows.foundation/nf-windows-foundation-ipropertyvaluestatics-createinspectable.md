# IPropertyValueStatics::CreateInspectable (windows.foundation.h)

## Description

Creates a new [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object that contains the specified [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) object.

## Parameters

### `value` [in]

Type: **[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)***

The object to store.

### `propertyValue` [out, retval]

Type: **[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)****

A pointer to a new object that contains *value*.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property value was created successfully. |
| **E_POINTER** | *value* is **NULL**. |
| **E_OUTOFMEMORY** | The [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object could not be created. |

## Remarks

Use the **CreateInspectable** method to store a value in an [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object. You can add the **IPropertyValue** object to a property store. Use the [GetInspectable](https://learn.microsoft.com/previous-versions/visualstudio) method to retrieve the value from the **IPropertyValue** object.

## See also

[IPropertyValue::GetInspectable](https://learn.microsoft.com/previous-versions/visualstudio)

[IPropertyValueStatics](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvaluestatics)