# PSPropertyBag_ReadStr function

## Description

Reads the string data value of a property in a property bag.

## Parameters

### `propBag` [in]

Type: **[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag)***

A pointer to an [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) object that represents the property bag in which the property is stored.

### `propName` [in]

Type: **LPCWSTR**

A null-terminated property name string.

### `value` [out]

Type: **LPCWSTR**

When this function returns, contains a pointer to a string property value.

### `characterCount` [out]

Type: **int**

This function returns the integer that represents the size (maximum number of characters) of the *value* parameter being returned.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The property bag property function API converts between window types and the **VARIANT** type that is used to express values in a property bag. Doing so eases property bag usage, simplifies applications, and avoids common coding errors.

## See also

[PSPropertyBag_WriteStr](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertybag_writestr)