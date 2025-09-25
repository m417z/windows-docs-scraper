# PropVariantToStringWithDefault function

## Description

Extracts the string property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value exists, then the specified default value is returned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pszDefault` [in]

Type: **LPCWSTR**

Pointer to a default Unicode string value, for use where no value currently exists. May be **NULL**.

## Return value

Type: **PCWSTR**

Returns string value or default, or the default.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a string value and would like to use a default value if it does not. For instance, an application obtaining values from a property store can use this to safely extract the string value for string properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_LPWSTR or VT_BSTR, this helper function returns a pointer to the value in the source **PROPVARIANT**. If the source **PROPVARIANT** has type VT_EMPTY or a conversion is not possible, then [PropVariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringwithdefault) will return the default provided by *pszDefault*.

Note that this function will return pointers to data supplied in the parameters. Thus the application must ensure that the data supplied to the parameters remains valid until the result is no longer in use.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringwithdefault) to access a string value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_Title, &propvar);
if (SUCCEEDED(hr))
{
     // PKEY_Title is expected to produce a VT_LPWSTR or VT_EMPTY value.
     // The application developer decided to treat VT_EMPTY or invalid values as ""
     PCWSTR pszTitle = PropVariantToStringWithDefault(propvar, L"");
     // pszTitle is now valid.
     PropVariantClear(&propvar);
}
// ... later in the program ...
hr = ppropstore->GetValue(PKEY_Comment, &propvar);
if (SUCCEEDED(hr))
{
         // PKEY_Comment is expected to produce a VT_LPWSTR or VT_EMPTY value.
         // The application developer decided to treat VT_EMPTY as NULL
         PCWSTR pszComment = PropVariantToStringWithDefault(propvar, NULL);
         if (pszComment)
         {
                 // pszComment is valid
         }
         PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)

[PropVariantToStringAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringalloc)

[VariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostring)