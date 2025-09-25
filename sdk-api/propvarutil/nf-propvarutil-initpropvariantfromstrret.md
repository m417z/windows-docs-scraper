# InitPropVariantFromStrRet function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a string stored in a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure.

## Parameters

### `pstrret` [in, out]

Type: **[STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret)***

Pointer to a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure that contains the string.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

PIDL of the item whose details are being retrieved.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_LPWSTR propvariant.

**Note** This function frees the memory used for the [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) contents.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromStrRet](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstrret).

```cpp
// STRRET strret;
// PCUITEMID_CHILD pidl;
// Assume variables strret and pidl are initialized and valid.
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromStrRet(strret, pidl, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_LPWSTR.
    PropVariantClear(&propvar);

    // Any allocated memory associated with strret has been freed.
}
```

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[InitVariantFromStrRet](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstrret)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)

[PropVariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringwithdefault)