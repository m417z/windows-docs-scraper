# PSPropertyBag_ReadStream function

## Description

Reads the data stream stored in a given property contained in a specified property bag.

## Parameters

### `propBag` [in]

Type: **[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag)***

A pointer to an [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) object, that represents the property bag in which the property is stored.

### `propName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated property name string.

### `value` [out]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

The address of a pointer that, when this function returns successfully, receives the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller of the [PSPropertyBag_ReadStream](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertybag_readstream) function needs to call a [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object returned by this function.

[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) and [IPersistPropertyBag](https://learn.microsoft.com/windows/win32/api/ocidl/nn-ocidl-ipersistpropertybag) optimize Save As Text functionality. **IPropertyBag** and [IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85)) provide an object with a property bag in which the object can save its properties persistently. **IPropertyBag2** allows the object to obtain type information for each property: [IPropertyBag2::Read](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768194(v=vs.85)) causes one or more properties to be read from the property bag, and [IPropertyBag2::Write](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768195(v=vs.85)) causes one or more properties to be saved into the property bag.

## See also

[PSPropertyBag_WriteStream](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertybag_writestream)