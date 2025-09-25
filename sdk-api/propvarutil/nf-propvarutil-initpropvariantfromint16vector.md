# InitPropVariantFromInt16Vector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a specified vector of 16-bit integer values.

## Parameters

### `prgn` [in]

Type: **const SHORT***

Pointer to a source vector of **SHORT** values. If this parameter is **NULL**, the vector is initialized with zeros.

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

Creates a VT_VECTOR | VT_I2 propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint16vector).

```cpp
SHORT rgShorts[] = {3, 1, 4};
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromInt16Vector(rgShorts, ARRAYSIZE(rgShorts), &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_I2.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint16)

[InitVariantFromInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint16)

[PropVariantToInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16vector)