# InitPropVariantFromUInt64Vector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a vector of 64-bit unsigned integers.

## Parameters

### `prgn` [in]

Type: **const ULONGLONG***

Pointer to a source vector of **ULONGLONG** values. If this parameter is **NULL**, the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is initialized with zeros.

### `cElems` [in]

Type: **ULONG**

Number of elements in the vector pointed to by *prgn*.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_VECTOR | VT_UI8 propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromUInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint64vector).

```cpp
ULONGLONG rgLongs[] = {4, 7};
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromUInt32Vector(rgLongs, ARRAYSIZE(rgLongs), &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_UI8.
    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint64)

[InitVariantFromUInt64Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint64array)

[PropVariantToUInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64vector)