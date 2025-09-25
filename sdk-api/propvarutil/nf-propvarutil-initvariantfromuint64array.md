# InitVariantFromUInt64Array function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an array of unsigned 64-bit integer values.

## Parameters

### `prgn` [in]

Type: **const ULONGLONG***

Pointer to the source array of **ULONGLONG** values.

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

Creates a VT_ARRAY | VT_UI8 variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromUInt64Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint64array).

```cpp
ULONGLONG rgLongs[] = {4, 2};
VARIANT var;

HRESULT hr = InitVariantFromUInt64Array(rgLongs, ARRAYSIZE(rgLongs), &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_UI8.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromUInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint64vector)

[InitVariantFromUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint64)

[VariantToUInt64Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint64array)