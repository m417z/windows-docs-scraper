# InitVariantFromUInt64 function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an unsigned 64-bit integer value.

## Parameters

### `ullVal` [in]

Type: **ULONGLONG**

Source **ULONGLONG** value.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_UI8 variant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint64).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromUInt64(3176, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_UI8.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint64)

[VariantToUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint64)

[VariantToUInt64WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint64withdefault)