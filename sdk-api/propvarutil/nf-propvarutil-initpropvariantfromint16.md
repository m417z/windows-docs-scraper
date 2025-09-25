# InitPropVariantFromInt16 function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a 16-bit integer value.

## Parameters

### `nVal` [in]

Type: **SHORT**

The source **SHORT** value.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates a VT_I2 propvariant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint16).

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromInt16(42, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_I2.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint16vector)

[InitVariantFromInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromint16)

[PropVariantToInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16)

[PropVariantToInt16WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16withdefault)