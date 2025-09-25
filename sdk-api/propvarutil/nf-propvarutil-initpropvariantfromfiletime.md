# InitPropVariantFromFileTime function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on information stored in a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Parameters

### `pftIn` [in]

Type: **const FILETIME***

Pointer to the date and time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_FILETIME propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletime).

```cpp
FILETIME ft;
PROPVARIANT propvar;

GetSystemTimeAsFileTime(&ft);

HRESULT hr = InitPropVariantFromFileTime(&ft, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_FILETIME.

    PropVariantClear(&propvar);
}
```

## See also

[GetSystemTimeAsFileTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeasfiletime)

[InitPropVariantFromFileTimeVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletimevector)

[InitVariantFromFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromfiletime)

[PropVariantToFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletime)