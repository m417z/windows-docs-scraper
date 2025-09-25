# InitVariantFromUInt32Array function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an array of unsigned 32-bit integer values.

## Parameters

### `prgn` [in]

Type: **const ULONG***

Pointer to the source array of **ULONG** values.

### `cElems` [in]

Type: **ULONG**

The number of elements in the array pointed to by *prgn*.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_ARRAY | VT_UI4 variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromUInt32Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint32array).

```cpp
ULONG rgLongs[] = {4, 2};
VARIANT var;

HRESULT hr = InitVariantFromUInt32Array(rgLongs, ARRAYSIZE(rgLongs), &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_UI4.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromUInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint32vector)

[InitVariantFromUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint32)

[VariantToUInt32Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint32array)