# InitVariantFromFileTime function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with the contents of a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Parameters

### `pft` [in]

Type: **const FILETIME***

Pointer to date and time information stored in a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_DATE variant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromfiletime).

```cpp
VARIANT var;
FILETIME ft;

GetSystemTimeAsFileTime(&ft);

HRESULT hr = InitVariantFromFileTime(&ft, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_DATE.
    VariantClear(&propvar);
}
```

## See also

[GetSystemTimeAsFileTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeasfiletime)

[InitPropVariantFromFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletime)

[VariantToFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttofiletime)