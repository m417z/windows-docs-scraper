# InitPropVariantFromInt64 function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a specified **Int64** value.

## Parameters

### `llVal` [in]

Type: **LONGLONG**

The source **LONGLONG** value.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_I8 propvariant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint64).

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromInt64(4096, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_I8.

    PropVariantClear(&propvar);
}
```

## See also

[InitVariantFromInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint64)

[PropVariantToInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64)

[PropVariantToInt64WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64withdefault)