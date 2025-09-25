# InitVariantFromInt16Array function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an array of 16-bit integer values.

## Parameters

### `prgn` [in]

Type: **const SHORT***

Pointer to the source array of **SHORT** values.

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

Creates a VT_ARRAY | VT_I2 variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromInt16Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint16array).

```cpp
SHORT rgShorts[] = {3, 1};
VARIANT var;

HRESULT hr = InitVariantFromInt16Array(rgShorts, ARRAYSIZE(rgShorts), &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_I2.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint16vector)

[InitVariantFromInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint16)

[VariantToInt16Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint16array)