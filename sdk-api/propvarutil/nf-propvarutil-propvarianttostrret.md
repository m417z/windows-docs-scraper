# PropVariantToStrRet function

## Description

Extracts a string from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure and places it into a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pstrret` [out]

Type: **[STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret)***

Points to the [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure. When this function returns, the structure has been initialized to contain a copy of the extracted string.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in applications that wish to convert a string value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure. For instance, an application implementing [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) may find this function useful.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_LPWSTR or VT_BSTR, this function extracts the string and places it into the [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a string. If a conversion is not possible, [PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring) will return a failure code. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, VT_EMPTY is successfully converted to "".

In addition to the conversions provided by [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype), the following special cases apply to [PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring).

* Vector-valued [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)s are converted to strings by separating each element with using "; ". For example, [PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring) converts a vector of 3 integers, {3, 1, 4}, to the string "3; 1; 4". The semicolon is independent of the current locale.
* VT_BLOB, VT_STREAM, VT_STREAMED_OBJECT, and VT_UNKNOWN values are converted to strings using an unsupported encoding. It is not possible to decode strings created in this way and the format may change in the future.

If the extraction is successful, the function will initialize uType member of the [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure with STRRET_WSTR and set the pOleStr member of that structure to point to an allocated copy of the string. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) or [StrRetToStr](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettostra) to free this string when it is no longer needed.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring) to access a string value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;

// Assume variable ppropstore is initialized and valid

PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_FileName, &propvar);

if (SUCCEEDED(hr))

{

    // PKEY_FileName is expected to produce a VT_LPWSTR or VT_EMPTY value.

    // PropVariantToStrRet will convert VT_EMPTY to "".

    // If this were an implementation of IShellFolder::GetDisplayNameOf, strName would be a parameter and the caller would free the memory associated with the STRRET

    STRRET strName;

    hr = PropVariantToStrRet(propvar, &strName);

    if (SUCCEEDED(hr))

    {

        // strName is now valid

        if (strName.uType == STRRET_WSTR)

        {

            CoTaskMemFree(strName.pOleStr);

        }

    }

    else

    {

        // the extraction failed

    }

    PropVariantClear(&propvar);

}
```

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantGetStringElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetstringelem)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)

[PropVariantToStringAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringalloc)

[PropVariantToStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringvector)

[StrRetToStr](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettostra)

[VariantToStrRet](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostrret)