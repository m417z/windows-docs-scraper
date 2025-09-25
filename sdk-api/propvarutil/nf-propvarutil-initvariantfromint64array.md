# InitVariantFromInt64Array function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an array of 64-bit integer values.

## Parameters

### `prgn` [in]

Type: **const LONGLONG***

Pointer to the source array of **LONGLONG** values.

### `cElems` [in]

Type: **ULONG**

The number of elements in the array pointed to by *prgn*.

The number of array elements.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_ARRAY | VT_I8 variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromInt64Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint64array).

```cpp
LONGLONG rgLongs[] = {4, 2};
VARIANT var;

HRESULT hr = InitVariantFromInt64Array(rgLongs, ARRAYSIZE(rgLongs), &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_I8.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint64vector)

[InitVariantFromInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint64)

[VariantToInt64Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint64array)