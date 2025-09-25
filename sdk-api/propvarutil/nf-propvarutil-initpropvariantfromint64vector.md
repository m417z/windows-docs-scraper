# InitPropVariantFromInt64Vector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a vector of **Int64** values.

## Parameters

### `prgn` [in]

Type: **const LONGLONG***

Pointer to a source vector of **LONGLONG** values. If this parameter is **NULL**, the vector is initialized with zeros.

### `cElems` [in]

Type: **ULONG**

The number of elements in the vector.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_VECTOR | VT_I8 propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint64vector).

```cpp
LONGLONG rgLongLongs[] = {4, 7};
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromInt64Vector(rgLongLongs, ARRAYSIZE(rgLongLongs), &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_I8.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint64)

[InitVariantFromInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint64)

[PropVariantToInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64vector)