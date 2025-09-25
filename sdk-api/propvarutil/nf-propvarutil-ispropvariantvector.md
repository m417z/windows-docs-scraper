# IsPropVariantVector function

## Description

Specifies whether a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure has a vector type.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure being queried.

## Return value

Type: **BOOL**

Returns **TRUE** if *propvar* is a VT_ARRAY | VT_VECTOR [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant); otherwise, **FALSE**.

## Remarks

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.