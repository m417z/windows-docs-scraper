# InitPropVariantFromString function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a specified string.

## Parameters

### `psz` [in]

Type: **PCWSTR**

Pointer to a buffer that contains the source Unicode string.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring).

```cpp
PROPVARIANT propvar;
HRESULT hr = InitPropVariantFromString(L"Hello World", &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_LPWSTR.
    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromStringAsVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringasvector)

[InitPropVariantFromStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringvector)

[InitVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstring)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)

[PropVariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringwithdefault)