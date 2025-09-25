# InitPropVariantFromInt32 function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a 32-bit integer value.

## Parameters

### `lVal` [in]

Type: **LONG**

The source **LONG** value.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_I4 propvariant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint32).

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromInt32(127, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_I4.

    PropVariantClear(&propvar);
}
```

## See also

[InitVariantFromInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint32)

[PropVariantToInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32)

[PropVariantToInt32WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32withdefault)