# PropVariantToStringVector function

## Description

Extracts a vector of strings from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `prgsz` [out]

Type: **PWSTR***

Pointer to a vector of string pointers. When this function returns, the buffer has been initialized with *pcElem* elements pointing to newly allocated strings containing the data extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

### `crgsz` [in]

Type: **ULONG**

Size of the buffer pointed to by *prgsz*, in elements.

### `pcElem` [out]

Type: **ULONG***

 When this function returns, contains the count of strings extracted from source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **TYPE_E_BUFFERTOOSMALL** | The source[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) contained more than *crgsz* values. The buffer pointed to by *prgsz*. |
| **E_INVALIDARG** | The[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a vector of string values with a fixed number of elements.

This function works for the following [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) types:

* VT_VECTOR | VT_LPWSTR
* VT_VECTOR | VT_BSTR
* VT_ARRAY | VT_BSTR

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has a supported type, this helper function extracts up to *crgsz* string values and places an allocated copy of each into the buffer pointed to by prgsz. If the **PROPVARIANT** contains more elements than will fit into the *prgsz* buffer, this function returns an error and sets *pcElem* to 0.

Since each string in pointed to by the output buffer has been newly allocated, the calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free each string in the output buffer when they are no longer needed.

If a **BSTR** in the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is **NULL**, it is converted to a newly allocated string containing "" in the output.

#### Examples

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid
LPWSTR rgszStrings; // The application is expecting propvar to hold 4 strings in a vector
ULONG cElems;
HRESULT hr = PropVariantToStringVector(propvar, rgszStrings, ARRAYSIZE(rgszStrings), &cElems);
if (SUCCEEDED(hr))
{
     if (cElems == ARRAYSIZE(rgszStrings))
     {
         // The application got 4 string which are now stored in rgszStrings
     }
     else
     {
         // The application got cElems which are stored in the first cElems elements of rgLongs
     }

    // Free the cElems strings that PropVariantToStringVector allocated
    for (ULONG i = 0; i < cElems; i++)
    {
        CoTaskMemFree(rgszStrings[i]);
    }
}
```

## See also

[InitPropVariantFromStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringvector)

[PropVariantGetStringElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetstringelem)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)

[PropVariantToStringVectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringvectoralloc)

[VariantToStringArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostringarray)