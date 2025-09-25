# InitVariantFromInt32Array function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an array of 32-bit integer values.

## Parameters

### `prgn` [in]

Type: **const LONG***

Pointer to the source array of **LONG** values.

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

Creates a VT_ARRAY | VT_I4 variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromInt32Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint32array).

```cpp
LONG rgLongs[] = {4, 2};
VARIANT var;

HRESULT hr = InitVariantFromInt32Array(rgLongs, ARRAYSIZE(rgLongs), &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_I4.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint32vector)

[InitVariantFromInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint32)

[VariantToInt32Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint32array)