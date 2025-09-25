# IPropertyValueStatics::CreateStringArray (windows.foundation.h)

## Description

Creates a new [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) object that contains the specified array of string values.

## Parameters

### `__valueSize` [in]

Type: **UINT32**

The number of values in the array.

### `value` [in]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)***

The array of string values to store.

### `propertyValue` [out, retval]

Type: **[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)****

A pointer to a new object that contains *value*. Use the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to get the [IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) interface for the object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPropertyValue::GetStringArray](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nf-windows-foundation-ipropertyvalue-getstringarray)

[IPropertyValueStatics](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvaluestatics)