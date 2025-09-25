# InitVariantFromFileTimeArray function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with an array of [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structures.

## Parameters

### `prgft` [in]

Type: **const FILETIME***

Pointer to an array of [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structures.

### `cElems` [in]

Type: **ULONG**

The number of elements in the array pointed to by *prgft*.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_ARRAY | VT_DATE variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromFileTimeArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromfiletimearray).

```cpp
// FILETIME rgFileTimes[3];
// Assume variable rgFileTimes is initialized and valid.
VARIANT var;

HRESULT hr = InitVariantFromFileTimeArray(rgFileTimes, ARRAYSIZE(rgFileTimes), &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_DATE.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromFileTimeVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletimevector)