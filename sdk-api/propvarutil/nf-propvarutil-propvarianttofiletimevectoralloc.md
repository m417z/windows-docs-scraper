# PropVariantToFileTimeVectorAlloc function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a newly-allocated FILETIME vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pprgft` [out]

Type: **FILETIME****

 When this function returns, contains a pointer to a vector of FILETIME values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of FILETIME elements extracted from source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **E_INVALIDARG** | The[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a FILETIME vector value.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_VECTOR | VT_FILETIME, this function extracts a vector of FILETIMEs values into a newly allocated vector of FILETIME values. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the vector pointed to by *pprgft* when it is no longer needed.

The output FILETIMEs will use the same time zone as the source FILETIMEs.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToFileTimeVectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletimevectoralloc) to access a FILETIME vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid.
// The application is expecting propvar to contain a vector of FILETIME values.
BOOL *prgTimes;
ULONG cTimes;
HRESULT hr = PropVariantToBooleanVectorAlloc(propvar, &prgTimes, &cTimes);
if (SUCCEEDED(hr))
{
     // prgTimes now points to a vector of cTimes file times.
     CoTaskMemFree(prgTimes);
}
```

## See also

[InitPropVariantFromFileTimeVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletimevector)

[PropVariantToFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletime)

[PropVariantToFileTimeVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletimevector)