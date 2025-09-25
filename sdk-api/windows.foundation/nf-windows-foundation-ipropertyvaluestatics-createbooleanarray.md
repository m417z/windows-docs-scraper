# IPropertyValueStatics::CreateBooleanArray (windows.foundation.h)

## Description

Creates a new [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object that contains the specified array of 8-bit Boolean values.

## Parameters

### `__valueSize` [in]

Type: **UINT32**

The number of values in the array.

### `value` [in]

Type: **boolean***

The array of 8-bit Boolean values to store.

### `propertyValue` [out, retval]

Type: **[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)****

A pointer to a new object that contains *value*. Use the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to get the [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) interface for the object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPropertyValue::GetBooleanArray](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nf-windows-foundation-ipropertyvalue-getbooleanarray)

[IPropertyValueStatics](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvaluestatics)