# InitPropVariantFromFileTimeVector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure from a specified vector of [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) values.

## Parameters

### `prgft` [in, optional]

Type: **const FILETIME***

Pointer to the date and time as a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) vector. If this value is **NULL**, the elements pointed to by the **cafiletime.pElems** structure member is initialized with (FILETIME)0.

### `cElems` [in]

Type: **ULONG**

The number of vector elements.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_VECTOR | VT_FILETIME propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromFileTimeVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletimevector).

```cpp
// FILETIME rgFileTime[];
// Assume variable rgFileTime is initialized and valid.
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromFileTimeVector(rgFileTime, ARRAYSIZE(rgFileTime), &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_FILETIME.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletime)

[InitVariantFromFileTimeArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromfiletimearray)

[PropVariantToFileTimeVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletimevector)