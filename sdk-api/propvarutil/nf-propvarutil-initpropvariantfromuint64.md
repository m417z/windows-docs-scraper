# InitPropVariantFromUInt64 function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure with a 64-bit unsigned integer value.

## Parameters

### `ullVal` [in]

Type: **ULONGLONG**

Source **ULONGLONG** value.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_UI8 propvariant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint64).

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromUInt64(563, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_UI8.
    PropVariantClear(&propvar);
}
```

## See also

[InitVariantFromUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromuint64)

[PropVariantToUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64)

[PropVariantToUInt64WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64withdefault)