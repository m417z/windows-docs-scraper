# InitVariantFromDispatch function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure based on an instance of an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) object.

## Parameters

### `pdisp` [in]

Type: **[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)***

Pointer to the source [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch).

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a **VT_DISPATCH** variant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromDispatch](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdispatch).

```cpp
// IDispatch *pDispatch;
// Assume variable pDispatch is initialized and valid.
VARIANT var;

HRESULT hr = InitVariantFromDispatch(pDispatch, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_DISPATCH.
    VariantClear(&propvar);
}
```