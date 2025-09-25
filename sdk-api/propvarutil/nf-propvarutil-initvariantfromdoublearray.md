# InitVariantFromDoubleArray function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an array of values of type DOUBLE.

## Parameters

### `prgn` [in]

Type: **const DOUBLE***

Pointer to the source array of DOUBLE values.

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

Creates a VT_ARRAY | VT_R8 variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdoublearray).

```cpp
DOUBLE rgDoubles[] = {34.7, 12.0};
VARIANT var;

HRESULT hr = InitVariantFromDoubleArray(rgDoubles, ARRAYSIZE(rgDoubles), &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_R8.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdoublevector)

[InitVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdouble)

[VariantToDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublearray)