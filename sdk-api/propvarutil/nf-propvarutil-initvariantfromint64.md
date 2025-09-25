# InitVariantFromInt64 function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with a 64-bit integer value.

## Parameters

### `llVal` [in]

Type: **LONGLONG**

Source **LONGLONG** value.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_I8 variant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint64).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromInt64(3176, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_I8.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint64)

[VariantToInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint64)

[VariantToInt64WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint64withdefault)