# InitVariantFromUInt16 function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an unsigned 16-bit integer value.

## Parameters

### `uiVal` [in]

Type: **USHORT**

Source **USHORT** value.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_UI2 variant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint16).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromUInt16(3, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_UI2.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint16)

[VariantToUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint16)

[VariantToUInt16WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint16withdefault)