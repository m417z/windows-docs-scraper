# InitPropVariantFromInt32Vector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a vector of 32-bit integer values.

## Parameters

### `prgn` [in]

Type: **const LONG***

Pointer to a source vector of **LONG** values. If this parameter is **NULL**, the vector is initialized with zeros.

### `cElems` [in]

Type: **ULONG**

The number of vector elements.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_VECTOR | VT_I4 propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint32vector).

```cpp
LONG rgLongs[] = {1, 2, 7};
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromInt32Vector(rgLongs, ARRAYSIZE(rgLongs), &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_I4.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint32)

[InitVariantFromInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint32)

[PropVariantToInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32vector)