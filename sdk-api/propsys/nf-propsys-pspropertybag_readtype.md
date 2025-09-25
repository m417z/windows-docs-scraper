# PSPropertyBag_ReadType function

## Description

Reads the type of data value of a property that is stored in a property bag.

## Parameters

### `propBag` [in]

Type: **[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag)***

A pointer to an [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) object, that represents the property bag in which the property is stored.

### `propName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated property name string.

### `var` [out]

Type: **VARIANT***

Returns on successful function completion a pointer to a **VARIANT** data type that contains the property value.

### `type` [out]

Type: **VARTYPE***

If *type* is VT_EMPTY, this function reads the **VARIANT** of the property in the IPropertyBag *propBag* parameter. If *type* is not VT_EMPTY and not the same as the **VARIANT** read, then this function attempts to convert the **VARIANT** read to the **VARTYPE** defined by *type* parameter before returning.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) and [IPersistPropertyBag](https://learn.microsoft.com/windows/win32/api/ocidl/nn-ocidl-ipersistpropertybag) optimize Save As Text functionality. **IPropertyBag** and [IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85)) provide an object with a property bag in which the object can save its properties persistently. **IPropertyBag2** allows the object to obtain type information for each property: [IPropertyBag2::Read](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768194(v=vs.85)) causes one or more properties to be read from the property bag, and [IPropertyBag2::Write](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768195(v=vs.85)) causes one or more properties to be saved into the property bag.

## See also

[PSPropertyBag_Delete](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertybag_delete)