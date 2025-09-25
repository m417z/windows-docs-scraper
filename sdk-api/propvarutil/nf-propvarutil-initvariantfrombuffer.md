# InitVariantFromBuffer function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with the contents of a buffer.

## Parameters

### `pv` [in]

Type: **const VOID***

Pointer to the source buffer.

### `cb` [in]

Type: **UINT**

The length of the buffer, in bytes.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_ARRAY | VT_UI1 variant..

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfrombuffer).

```cpp
// void *pv;
// UINT cb;
// Assume variable pv and cb are initialized and valid. pv points to a
// buffer and cb contains the size of the buffer in bytes.
VARIANT var;

HRESULT hr = InitVariantFromBuffer(pv, cb, & var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_UI1.
    VariantClear(&var);
}
```

## See also

[InitPropVariantFromBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfrombuffer)

[VariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobuffer)