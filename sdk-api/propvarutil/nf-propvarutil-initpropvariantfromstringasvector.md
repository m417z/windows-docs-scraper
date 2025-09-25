# InitPropVariantFromStringAsVector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure from a specified string. The string is parsed as a semi-colon delimited list (for example: "A;B;C").

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

Creates a VT_VECTOR | VT_LPWSTR propvariant. It parses the source string as a semicolon list of values. The string "a; b; c" creates a vector with three values. Leading and trailing whitespace are removed, and empty values are omitted.

If *psz* is **NULL** or contains no values, the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure is initialized as VT_EMPTY.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromStringAsVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringasvector).

```cpp
PROPVARIANT propvar;
HRESULT hr = InitPropVariantFromStringAsVector(L"a; b; c", &propvar);

if (SUCCEEDED(hr))
{
    // propvar now has type VT_VECTOR | VT_LPWSTR and contains {"a", "b", "c"}.
    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[InitPropVariantFromStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringvector)

[InitVariantFromStringArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstringarray)

[PropVariantToStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringvector)