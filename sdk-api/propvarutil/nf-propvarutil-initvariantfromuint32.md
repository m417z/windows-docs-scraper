# InitVariantFromUInt32 function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an unsigned 32-bit integer value.

## Parameters

### `ulVal` [in]

Type: **ULONG**

Source **ULONG** value.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_UI4 variant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint32).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromUInt32(3, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_UI4.

    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint32)

[VariantToUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint32)

[VariantToUInt32WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint32withdefault)