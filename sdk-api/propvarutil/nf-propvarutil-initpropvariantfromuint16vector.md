# InitPropVariantFromUInt16Vector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a vector of 16-bit unsigned integer values.

## Parameters

### `prgn` [in]

Type: **const USHORT***

Pointer to a source vector of **USHORT** values. If this parameter is **NULL**, the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is initialized with zeros.

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

Creates a VT_VECTOR | VT_UI2 propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromUInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint16vector).

```cpp
USHORT rgShorts[] = {4, 7};
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromUInt16Vector(rgShorts, ARRAYSIZE(rgShorts), &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_UI2.
     PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint16)

[InitVariantFromUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint16)

[PropVariantToUInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint16vector)