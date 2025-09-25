# PropVariantToFileTimeVector function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a FILETIME vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `prgft` [out]

Type: **FILETIME***

 Points to a buffer containing *crgft* FILETIME values. When this function returns, the buffer has been initialized with *pcElem* FILETIME elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `crgft` [in]

Type: **ULONG**

 Size in elements of the buffer pointed to by *prgft*.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of FILETIME elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **TYPE_E_BUFFERTOOSMALL** | The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) contained more than crgn values. The buffer pointed to by *prgft*. |
| **E_INVALIDARG** | The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a filetime vector value with a fixed number of elements.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_VECTOR | VT_FILETIME, this helper function extracts up to *crgft* FILETIME values and places them into the buffer pointed to by *prgft*. If the **PROPVARIANT** contains more elements than will fit into the *prgft* buffer, this function returns an error and sets *pcElem* to 0.

The output FILETIMEs will use the same time zone as the source FILETIMEs.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToFileTimeVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletimevector) to access a FILETIME vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid
FILETIME rgTimes[4]; // The application is expecting propvar to hold 4 FILETIMEs in a vector
ULONG cTimes;
HRESULT hr = PropVariantToFileTimeVector(propvar, rgTime, ARRAYSIZE(rgTime), &cTimes);
if (SUCCEEDED(hr))
{
     if (cTimes == ARRAYSIZE(rgTime))
     {
         // The application got 4 FILETIMEs which are now stored in rgTime
     }
     else
     {
         // The application got cTimes which are stored in the first cTimes elements of rgTime
     }
}
```

## See also

[InitPropVariantFromFileTimeVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletimevector)

[PropVariantToFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletime)

[PropVariantToFileTimeVectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletimevectoralloc)