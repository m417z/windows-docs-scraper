# PropVariantToStringVectorAlloc function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a newly allocated strings in a newly allocated vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pprgsz` [out]

Type: **PWSTR****

When this function returns, contains a pointer to a vector of strings extracted from source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of string elements extracted from source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **E_INVALIDARG** | The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a vector of string values.

This helper function works for the following[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) types:

* VT_VECTOR | VT_LPWSTR
* VT_VECTOR | VT_BSTR
* VT_ARRAY | VT_BSTR

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has a supported type, this function extracts a vector of string values into a newly allocated vector of newly allocated strings. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release both the strings contained in the output vector, and the output vector itself, when they are no longer needed.

If a **BSTR** in the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is **NULL**, this function will place a newly allocated string containing "" into the output vector.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToStringVectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringvectoralloc) to access a string vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_Keywords, &propvar);
if (SUCCEEDED(hr))
{
         // PKEY_Keywords is expected to produce a VT_VECTOR | VT_LPWSTR, or VT_EMPTY
         // PropVariantToStringVectorAlloc will return an error for VT_EMPTY
         LPWSTR *prgKeywords;
         ULONG cElem;
         hr = PropVariantToStringVectorAlloc (propvar, &prgKeywords, &cElem);
         if (SUCCEEDED(hr))
         {
                 // prgKeywords contains cElem strings
                 for (ULONG i = 0; i < cElem; i++)
                 {
                          CoTaskMemFree(prgKeywords[i]);
                 }
                 CoTaskMemFree(prgKeywords);
         }
         else
         {
                 // propvar either is VT_EMPTY, or contains something other than a vector of  strings
         }
         PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringvector)

[PropVariantGetStringElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetstringelem)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)

[PropVariantToStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringvector)

[VariantToStringArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostringarray)