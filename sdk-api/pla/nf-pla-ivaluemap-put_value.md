# IValueMap::put_Value

## Description

Retrieves or sets the value of the collection.

This property is read/write.

## Parameters

## Remarks

Depending on the value of the [IValueMap::ValueMapType](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_valuemaptype) property, this value is either one of the values in the collection or the value derived by combining all the item values in the collection with the **OR** operator.

The variant type is VT_UI8 if the [ValueMapType](https://learn.microsoft.com/windows/win32/api/pla/ne-pla-valuemaptype) enumeration is **plaIndex**, **plaFlag** or **plaFlagArray**.

The variant type is VT_UI4 if the [ValueMapType](https://learn.microsoft.com/windows/win32/api/pla/ne-pla-valuemaptype) enumeration is **plaValidation**.

## See also

[IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap)

[IValueMap::ValueMapType](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_valuemaptype)