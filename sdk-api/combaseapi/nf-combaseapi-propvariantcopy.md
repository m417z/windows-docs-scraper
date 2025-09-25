# PropVariantCopy function

## Description

The
**PropVariantCopy** function
copies the contents of one
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure to another.

## Parameters

### `pvarDest` [in, out]

Pointer to an uninitialized
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that receives the copy.

### `pvarSrc` [in]

Pointer to the
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure to be copied.

## Return value

This function returns HRESULT.

## Remarks

Copies a
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure by value so the original *pvarSrc* and new *pvarDest* parameters may be freed independently with calls to
[PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear).
**PropVariantCopy** does not free the destination as the [VariantCopy](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-variantcopy) function does. For nonsimple
**PROPVARIANT** types such as VT_STREAM, VT_STORAGE, and so forth, which require a subobject, the copy is made by reference. The pointer is copied, and [IUnknown::AddRef](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) is called on it. It is illegal to pass **NULL** for either *pvarDest* or *pvarSrc*.

## See also

[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant), [PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear)