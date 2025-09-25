# IPerPropertyBrowsing::GetPredefinedStrings

## Description

Retrieves an array description strings for the allowable values that the specified property can accept.

## Parameters

### `dispID` [in]

The dispatch identifier of the property.

### `pCaStringsOut` [out]

A pointer to a caller-allocated, counted array structure that contains the element count and address of a method-allocated array of string pointers. This method also allocates memory for the string values containing the predefined names, and it stores the string pointers in the array. If the method fails, no memory is allocated, and the contents of the structure are undefined.

### `pCaCookiesOut` [out]

A pointer to the caller-allocated, counted array structure that contains the element count and address of a method-allocated array of **DWORD** values. The values in the array can be passed to [IPerPropertyBrowsing::GetPredefinedValue](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedvalue) to retrieve the value associated with the name in the same array position inside *pCaStringsOut*. If the method fails, no memory is allocated, and the contents of the structure are undefined.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | This method is not implemented and predefined names are not supported. |
| **E_POINTER** | The address in *pCaStringsOut* or *pCaCookiesOut* is not valid. For example, either parameter may be **NULL**. |

## Remarks

Each string returned in the array pointed to by *pCaStringsOut* has a matching token in the counted array pointed to by *pCaCookiesOut*, where the token can be passed to [IPerPropertyBrowsing::GetPredefinedValue](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedvalue) to get the actual value (a **VARIANT**) corresponding to the string.

Using the predefined strings, a caller can obtain a list of strings for populating user interface elements, such as a drop-down listbox. When the end user selects one of these strings as a value to assign to a property, the caller can then obtain the corresponding value through [IPerPropertyBrowsing::GetPredefinedValue](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedvalue).

### Notes to Callers

Both the [CALPOLESTR](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-calpolestr) and [CADWORD](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-cadword) structures passed to this method are caller-allocated. The caller is responsible for freeing each string pointed to from the **CALPOLESTR** array as well as the **CALPOLESTR** structure.

All memory is allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). The caller is responsible for freeing the strings and the array with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

Upon return from this method, the caller is responsible for all this memory and must free it when it is no longer needed. Code to achieve this appears as follows.

``` syntax
CALPOLESTR     castr;
CWDWORD        cadw;
ULONG          i;

pIPerPropertyBrowsing->GetPredefinedStrings(dispID, &castr, &cadw);

//...Use the strings and the cookies

CoTaskMemFree((void *)cadw.pElems);

for (i=0; i < castr.cElems; i++)
    CoTaskMemFree((void *)castr.pElems[i]);

CoTaskMemFree((void *)castr.pElems);

```

### Notes to Implementers

Support for predefined names and values is not required. If your object does not support these names, return E_NOTIMPL from this method. If this method is not implemented, [IPerPropertyBrowsing::GetPredefinedValue](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedvalue) must not be implemented either.

This method fills the **cElems** and **pElems** members of the [CADWORD](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-cadword) and [CALPOLESTR](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-calpolestr) structures. It allocates the arrays pointed to by these structures with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and fills those arrays. In the **CALPOLESTR** case, this method also allocates each string with **CoTaskMemAlloc**, storing each string pointer in the array.

## See also

[CADWORD](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-cadword)

[CALPOLESTR](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-calpolestr)

[IPerPropertyBrowsing](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iperpropertybrowsing)