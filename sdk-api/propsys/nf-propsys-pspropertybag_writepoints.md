# PSPropertyBag_WritePOINTS function

## Description

 Stores the property coordinates in a[POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structure of a specified property bag.

## Parameters

### `propBag` [in]

Type: **[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag)***

A pointer to an [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) object that represents the property bag in which the property is stored.

### `propName` [in]

Type: **LPCWSTR**

A null-terminated property name string.

### `value` [in]

Type: **const [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points)***

Pointer to a [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structure that specifies the coordinates to store in the property.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The property bag property function API converts between window types and the **VARIANT** type that is used to express values in a property bag. Doing so eases property bag usage, simplifies applications, and avoids common coding errors.

## See also

[PSPropertyBag_ReadPOINTS](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertybag_readpoints)