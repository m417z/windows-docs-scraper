# InitVariantFromResource function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure based on a string resource embedded in an executable file.

## Parameters

### `hinst` [in]

Type: **HINSTANCE**

Handle to an instance of the module whose executable file contains the string resource.

### `id` [in]

Type: **UINT**

Integer identifier of the string to be loaded.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_BSTR variant. If the resource does not exist, this function initializes the VARIANT as VT_EMPTY and returns a failure code.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromResource](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromresource).

```cpp
// HINSTANCE hinst;
// UINT id;
// Assume variables hinst and id are initialized and valid.
VARIANT var;

HRESULT hr = InitVariantFromResource(hinst, id, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_BSTR.
    VariantClear(&var);
}
```

## See also

[InitPropVariantFromResource](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromresource)

[InitVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstring)

[LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa)

[VariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostring)

[VariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostringwithdefault)