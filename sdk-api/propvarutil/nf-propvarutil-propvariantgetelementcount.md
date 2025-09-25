# PropVariantGetElementCount function

## Description

Retrieves the element count of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **ULONG**

Returns the element count of a VT_VECTOR or VT_ARRAY value: for single values, returns 1; for empty structures, returns 0.

## Remarks

This function works for all valid [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) types. See **PROPVARIANT** for the valid type combinations.

This function is useful to get the count of elements to iterate through using a looping statement, especially for iterations that call functions such as [PropVariantGetUInt32Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetuint32elem) or [PropVariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelem).