# PropVariantToBSTR function

## Description

Extracts the BSTR property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pbstrOut` [out]

Type: **[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)***

Pointer to the extracted property value if one exists; otherwise, contains an empty string.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a string value.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_BSTR** or VT_LPWSTR, this function extracts the string as a **BSTR** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a string. If a conversion is not possible, [PropVariantToBSTR](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobstr) returns a failure code and sets *pbstrOut* to **NULL**. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

**VT_EMPTY** is successfully converted to an allocated BSTR containing "".

The calling application is responsible for using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to release the **BSTR** pointed to by *pbstrOut* when it is no longer needed.

In addition to the conversions provided by [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype), the following special cases apply to [PropVariantToBSTR](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobstr).

* Vector-valued [PROPVARIANTs](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) are converted to strings by separating each element with using "; ". For example, [PropVariantToBSTR](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobstr) converts a vector of 3 integers, {3, 1, 4}, to the string "3; 1; 4". The semicolon is independent of the current locale.
* VT_BLOB, VT_STREAM, VT_STREAMED_OBJECT, and VT_UNKNOWN values are converted to strings through an unsupported encoding. It is not possible to decode strings created in this way and the format may change in the future.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToBSTR](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobstr) to access a string value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume the variable ppropstore is initialized and valid.
PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_Title, &propvar);

if (SUCCEEDED(hr))
{
    // PKEY_Title is expected to produce a VT_LPWSTR or VT_EMPTY value.
    // PropVariantToBSTR will convert VT_EMPTY to "".
    BSTR bstrTitle;

    hr = PropVariantToBSTR(propvar, &bstrTitle);

    if (SUCCEEDED(hr))
    {
        // bstrTitle is now valid.
    }
    else
    {
        // bstrTitle is always NULL.
    }
    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[PropVariantGetStringElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetstringelem)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)

[PropVariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringwithdefault)