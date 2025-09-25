# InitPropVariantFromUInt32Vector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a vector of 32-bit unsigned integer values.

## Parameters

### `prgn` [in]

Type: **const ULONG***

Pointer to a source vector of **ULONG** values. If this parameter is **NULL**, the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is initialized with zeros.

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

Creates a VT_VECTOR | VT_UI4 propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromUInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint32vector).

```cpp
ULONG rgLongs[] = {4, 7};
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromUInt32Vector(rgLongs, ARRAYSIZE(rgLongs), &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_UI4.
    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint32)

[InitVariantFromUInt32Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint32array)

[PropVariantToUInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32vector)