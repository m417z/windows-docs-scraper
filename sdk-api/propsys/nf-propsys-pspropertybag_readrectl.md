# PSPropertyBag_ReadRECTL function

## Description

Retrieves the coordinates of a rectangle stored in a property contained in a specified property bag.

## Parameters

### `propBag` [in]

Type: **[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag)***

A pointer to an [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) object that represents the property bag in which the property is stored.

### `propName` [in]

Type: **LPCWSTR**

A null-terminated property name string.

### `value` [out]

Type: **[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)***

When this function returns, contains a pointer to a [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure that contains the property coordinates.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The property bag property function API converts between window types and the **VARIANT** type that is used to express values in a property bag. Doing so eases property bag usage, simplifies applications, and avoids common coding errors.

## See also

[PSPropertyBag_WriteRECTL](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertybag_writerectl)