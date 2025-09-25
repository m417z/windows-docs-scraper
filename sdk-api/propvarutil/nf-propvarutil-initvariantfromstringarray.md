# InitVariantFromStringArray function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an array of strings.

## Parameters

### `prgsz` [in]

Type: **PCWSTR***

Pointer to an array of strings.

### `cElems` [in]

Type: **ULONG**

The number of elements in the array pointed to by *prgsz*.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_ARRAY | VT_BSTR variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromStringArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstringarray).

```cpp
PCWSTR rgStrings[] = {"dog", "cat"};
VARIANT var;

HRESULT hr = InitVariantFromStringArray(rgStrings, ARRAYSIZE(rgStrings), &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_BSTR.
    VariantClear(&var);
}
```

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[InitVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstring)

[VariantToStringArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostringarray)