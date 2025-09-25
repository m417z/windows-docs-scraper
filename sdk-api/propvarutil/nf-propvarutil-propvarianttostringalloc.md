# PropVariantToStringAlloc function

## Description

Extracts a string property value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `ppszOut` [out]

Type: **PWSTR***

When this function returns, contains a pointer to the extracted property value if one exists.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a string value.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_LPWSTR or VT_BSTR, this function extracts the string into a newly allocated buffer. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a string. If a conversion is not possible, [PropVariantToStringAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringalloc) will return a failure code and set *ppszOut* to **NULL**. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, **VT_EMPTY** is successfully converted to an allocated buffer containing "".

The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the string pointed to by *ppszOut* when it is no longer needed.

In addition to the conversions provided by [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype), the following special cases apply to [PropVariantToStringAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringalloc).

* Vector-valued PROPVARIANTs are converted to strings by separating each element with using "; ". For example, [PropVariantToStringAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringalloc) converts a vector of 3 integers, {3, 1, 4}, to the string "3; 1; 4". The semicolon is independent of the current locale.
* VT_BLOB, VT_STREAM, VT_STREAMED_OBJECT, and VT_UNKNOWN values are converted to strings using an unsupported encoding. It is not possible to decode strings created in this way and the format may change in the future.

#### Examples

```cpp
// IPropertyStore *ppropstore;

// Assume variable ppropstore is initialized and valid

PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_Title, &propvar);

if (SUCCEEDED(hr))

{

    // PKEY_Title is expected to produce a VT_LPWSTR or VT_EMPTY value.

    // PropVariantToStringAlloc will convert VT_EMPTY to "".

    LPWSTR pszTitle;

    hr = PropVariantToString(propvar, &pszTitle);

    if (SUCCEEDED(hr))

    {

        // pszTitle is now valid

    }

    else

    {

        // pszTitle is always NULL

    }

    PropVariantClear(&propvar);

}
```

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)

[PropVariantToStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringvector)

[VariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostring)