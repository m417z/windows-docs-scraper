# InitVariantFromInt32 function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with a 32-bit integer value.

## Parameters

### `lVal` [in]

Type: **LONG**

Source **LONG** value.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_I4 variant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint32).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromInt32(3, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_I4.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint32)

[VariantToInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint32)

[VariantToInt32WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint32withdefault)