# InitPropVariantFromBuffer function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure using the contents of a buffer.

## Parameters

### `pv` [in]

Type: **const void***

Pointer to the buffer.

### `cb` [in]

Type: **UINT**

The length of the buffer, in bytes.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_VECTOR | VT_UI1 propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfrombuffer).

```cpp
// void *pv;
// UINT cb;
// Assume variable pv and cb are initialized and valid. pv points to a buffer
// and cb contains the size of the buffer in bytes.
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromBuffer(pv, cb, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_UI1.

    PropVariantClear(&propvar);
}
```

## See also

[InitVariantFromBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfrombuffer)

[PropVariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobuffer)