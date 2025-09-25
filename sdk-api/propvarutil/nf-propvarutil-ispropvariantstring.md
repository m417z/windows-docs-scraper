# IsPropVariantString function

## Description

Specifies whether a specified [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure is a string type.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **BOOL**

Returns **TRUE** if *propvar* is a VT_LPWSTR or VT_BSTR [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant); otherwise, **FALSE**.

## Remarks

If this function returns **TRUE**, the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure referenced in *propvar* contains a Unicode string. To retrieve it, call [PropVariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringwithdefault) as shown here:

`PropVariantToStringWithDefault(propvar, NULL);`

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.