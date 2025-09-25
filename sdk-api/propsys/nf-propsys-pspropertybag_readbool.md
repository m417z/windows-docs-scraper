# PSPropertyBag_ReadBOOL function

## Description

Reads the **BOOL** data value of a property in a property bag.

## Parameters

### `propBag` [in]

Type: **[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag)***

A pointer to an [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) object that represents the property bag in which the property is stored.

### `propName` [in]

Type: **LPCWSTR**

A null-terminated property name string.

### `value` [out]

Type: **BOOL***

When this function returns successfully, contains a pointer to the value read from the property.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The property bag property function API converts between windows types and the **VARIANT** type that is used to express values in a property bag. Doing so eases property bag usage, simplifies applications, and avoids common coding errors.

## See also

[PSGetPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertysystem)

[PSPropertyBag_WriteBOOL](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertybag_writebool)