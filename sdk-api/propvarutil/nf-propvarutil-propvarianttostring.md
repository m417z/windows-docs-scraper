# PropVariantToString function

## Description

Extracts a string value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `psz` [out]

Type: **PWSTR**

Points to a string buffer. When this function returns, the buffer is initialized with a **NULL** terminated Unicode string value.

### `cch` [in]

Type: **UINT**

Size of the buffer pointed to by *psz*, in characters.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The value was extracted and the result buffer was **NULL** terminated. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | The copy operation failed due to insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. In situations where truncation is acceptable, this may not necessarily be seen as a failure condition. |
| **Some other error value** | The extraction failed for some other reason. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a string value. For instance, an application obtaining values from a property store can use this to safely extract a string value for string properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_LPWSTR or **VT_BSTR**, this function extracts the string and places it into the provided buffer. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a string. If a conversion is not possible, [PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring) will return a failure code and set *psz* to '\0'. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, **VT_EMPTY** is successfully converted to "".

In addition to the terminating **NULL**, at most *cch*-1 characters are written into the buffer pointed to by *psz*. If the value in the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is longer than will fit into the buffer, a truncated **NULL** Terminated copy of the string is written to the buffer and this function returns **STRSAFE_E_INSUFFICIENT_BUFFER**. The resulting string will always be **NULL** terminated.

In addition to the conversions provided by [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype), the following special cases apply to [PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring).

* Vector-valued [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)s are converted to strings by separating each element with using "; ". For example, [PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring) converts a vector of 3 integers, {3, 1, 4}, to the string "3; 1; 4". The semicolon is independent of the current locale.
* VT_BLOB, VT_STREAM, VT_STREAMED_OBJECT, and VT_UNKNOWN values are converted to strings using an unsupported encoding. It is not possible to decode strings created in this way and the format may change in the future.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring) to access a string value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;

// Assume variable ppropstore is initialized and valid

PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_Title, &propvar);

if (SUCCEEDED(hr))

{

    // PKEY_Title is expected to produce a VT_LPWSTR or VT_EMPTY value.

    // PropVariantToString will convert VT_EMPTY to "".

    // The application decided that it only needs the first 127 characters of the title, so the buffer

    // has size 128 to account for the terminating NULL.

    WCHAR szTitle[128];

    hr = PropVariantToString(propvar, szTitle, ARRAYSIZE(szTitle));

    if (SUCCEEDED(hr) || hr == STRSAFE_E_INSUFFICIENT_BUFFER)

    {

        // szTitle is now valid and contains up to 127 characters from propvar and a terminating NULL

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

[PropVariantToBSTR](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobstr)

[PropVariantToStringAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringalloc)

[PropVariantToStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringvector)

[VariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostring)