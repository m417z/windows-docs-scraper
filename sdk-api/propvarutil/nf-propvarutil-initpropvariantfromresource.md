# InitPropVariantFromResource function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a string resource embedded in an executable file.

## Parameters

### `hinst` [in]

Type: **HINSTANCE**

Handle to an instance of the module whose executable file contains the string resource.

### `id` [in]

Type: **UINT**

Integer identifier of the string to be loaded.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates a VT_LPWSTR propvariant. If the specified resource does not exist, it initializes the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) with an empty string. Resource strings longer than 1024 characters are truncated and null-terminated.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromResource](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromresource).

```cpp
// HINSTANCE hinst;
// UINT id;
// Assume variables hinst and id are initialized and valid.
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromResource(hinst, id, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_LPWSTR.
    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[InitVariantFromResource](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromresource)

[LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)

[PropVariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringwithdefault)