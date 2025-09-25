# InitVariantFromInt16 function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with a 16-bit integer value.

## Parameters

### `iVal` [in]

Type: **SHORT**

Source **SHORT** value.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_I2 variant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint16).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromInt16(3, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_I2.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint16)

[VariantToInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint16)

[VariantToInt16WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint16withdefault)