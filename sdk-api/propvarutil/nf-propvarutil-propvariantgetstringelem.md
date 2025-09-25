# PropVariantGetStringElem function

## Description

Extracts a single Unicode string element from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure of type VT_LPWSTR, VT_BSTR, VT_VECTOR | VT_LPWSTR, VT_VECTOR | VT_BSTR, or VT_ARRAY | VT_BSTR.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `iElem` [in]

Type: **ULONG**

The vector or array index; otherwise, *iElem* must be 0.

### `ppszVal` [out]

Type: **PWSTR***

When this function returns, contains the extracted string value. The calling application is responsible for freeing this string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when it is no longer needed.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function works for [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures of the following types:

* VT_LPWSTR
* VT_BSTR
* VT_VECTOR | VT_LPWSTR
* VT_VECTOR | VT_BSTR
* VT_ARRAY | VT_BSTR

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_LPWSTR or VT_BSTR, *iElem* must be 0. Otherwise *iElem* must be less than the number of elements in the vector or array. You can use [PropVariantGetElementCount](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelementcount) to obtain the number of elements in the vector or array.

If a BSTR element has a **NULL** pointer, this function allocates an empty string.

#### Examples

The following code example, to be included as part of a larger program, demonstrates how to use [PropVariantGetStringElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetstringelem) with an iteration statement to access the values in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid

if ((propvar.vt & VT_TYPEMASK) == VT_LPWSTR || (propvar.vt & VT_TYPEMASK) == VT_BSTR)
{
    UINT cElem = PropVariantGetElementCount(propvar);
    HRESULT hr = <mark type="const">S_OK</mark>;

    for (UINT iElem = 0; SUCCEEDED(hr) && iElem < cElem; iElem ++)
    {
        PWSTR pszValue;
        hr = PropVariantGetStringElem(propvar, iElem, &pszValue);

        if (SUCCEEDED(hr))
        {
            // pszValue is valid now
            CoTaskMemFree(pszValue);
        }
    }
}
```

## See also

[PropVariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelem)