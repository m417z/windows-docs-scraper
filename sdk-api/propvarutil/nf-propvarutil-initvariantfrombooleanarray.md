# InitVariantFromBooleanArray function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure from an array of Boolean values.

## Parameters

### `prgf` [in]

Type: **const BOOL***

Pointer to source array of Boolean values.

### `cElems` [in]

Type: **ULONG**

The number of elements in the array.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_ARRAY | VT_BOOL variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromBooleanArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfrombooleanarray).

```cpp
BOOL rgFlags[] = {TRUE, FALSE};
VARIANT var;

HRESULT hr = InitVariantFromBooleanArray(rgFlags, ARRAYSIZE(rgFlags), &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_BOOL.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromBooleanVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfrombooleanvector)

[VariantToBooleanArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobooleanarray)