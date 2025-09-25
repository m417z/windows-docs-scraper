# InitVariantFromString function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with a string.

## Parameters

### `psz` [in]

Type: **PCWSTR**

Pointer to a buffer that contains the source Unicode string. If this value is **NULL**, the function initializes the [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) with a **NULL** **BSTR**.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_BSTR variant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstring).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromString(L"This is a test", &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_BSTR.
    VariantClear(&var);
}
```

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[InitVariantFromStringArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstringarray)

[VariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostring)

[VariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostringwithdefault)