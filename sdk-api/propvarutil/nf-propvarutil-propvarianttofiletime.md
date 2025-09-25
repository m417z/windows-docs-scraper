# PropVariantToFileTime function

## Description

Extracts the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pstfOut` [in]

Type: **PSTIME_FLAGS**

Specifies one of the following time flags.

#### PSTF_UTC (0)

Indicates the output will use coordinated universal time.

#### PSTF_LOCAL (1)

Indicates the output will use local time.

### `pftOut` [out]

Type: **FILETIME***

When this function returns, contains the extracted [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a single filetime value. For instance, an application obtaining values from a property store can use this to safely extract a filetime value for filetime properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_FILETIME or VT_DATE, this helper function extracts the value as a FILETIME using the timezone specified by *pstfOut*. If the source **PROPVARIANT** is VT_EMPTY or any other type, this function returns a failure result.

The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) must be in Coordinated Universal Time (UTC). The PSTF_UTC and PSTF_LOCAL flags allow the calling application to specify what time zone the output should be converted to.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletime) to access a FILETIME value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_DateModified, &propvar);
if (SUCCEEDED(hr))
{
     // PKEY_DateModified is expected to produce a VT_FILETIME or VT_EMPTY value.
     // PropVariantToFileTime will return a failure code for VT_EMPTY
     FILETIME ftModified;
     hr = PropVariantToFileTime(propvar, PSTF_UTC, &ftModified);
     if (SUCCEEDED(hr))
     {
        // ftModified is now valid and contains a file time in UTC
     }
     else
     {
        // Unable to convert propvar to a FILETIME
     }
     PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletime)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToFileTimeVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletimevector)

[VariantToFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttofiletime)