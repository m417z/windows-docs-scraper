# SafeArrayPutElement function

## Description

Stores the data element at the specified location in the array.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

### `rgIndices` [in]

A vector of indexes for each dimension of the array. The right-most (least significant) dimension is rgIndices[0]. The left-most dimension is stored at `rgIndices[psa->cDims – 1]`.

### `pv` [in]

The data to assign to the array. The variant types VT_DISPATCH, VT_UNKNOWN, and VT_BSTR are pointers, and do not require another level of indirection.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADINDEX** | The specified index is not valid. |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_OUTOFMEMORY** | Memory could not be allocated for the element. |

## Remarks

This function automatically calls [SafeArrayLock](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraylock) and [SafeArrayUnlock](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayunlock) before and after assigning the element. If the data element is a string, object, or variant, the function copies it correctly when the safe array is destroyed. If the existing element is a string, object, or variant, it is cleared correctly. If the data element is a VT_DISPATCH or VT_UNKNOWN, **AddRef** is called to increment the object's reference count.

**Note** Multiple locks can be on an array. Elements can be put into an array while the array is locked by other operations.

For an example that demonstrates calling **SafeArrayPutElement**, see the COM Fundamentals Lines sample (CLines::Add in Lines.cpp).