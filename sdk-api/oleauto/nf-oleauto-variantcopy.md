# VariantCopy function

## Description

Frees the destination variant and makes a copy of the source variant.

## Parameters

### `pvargDest` [out]

The destination variant.

### `pvargSrc` [in]

The source variant.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_ARRAYISLOCKED** | The variant contains an array that is locked. |
| **DISP_E_BADVARTYPE** | The variant type is not a valid type of variant. |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

First, free any memory that is owned by pvargDest, such as [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) (pvargDest must point to a valid initialized variant, and not simply to an uninitialized memory location). Then pvargDest receives an exact copy of the contents of pvargSrc.

If pvargSrc is a VT_BSTR, a copy of the string is made. If pvargSrcis a VT_ARRAY, the entire array is copied. If pvargSrc is a VT_DISPATCH or VT_UNKNOWN, **AddRef** is called to increment the object's reference count.

If the variant to be copied is a COM object that is passed by reference, the vtfield of the pvargSrcparameter is VT_DISPATCH | VT_BYREF or VT_UNKNOWN | VT_BYREF. In this case, **VariantCopy** does not increment the reference count on the referenced object. Because the variant being copied is a pointer to a reference to an object, **VariantCopy** has no way to determine if it is necessary to increment the reference count of the object. It is therefore the responsibility of the caller to call **IUnknown::AddRef** on the object or not, as appropriate.

**Note** The **VariantCopy** method is not threadsafe.

## See also

[Variant Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/variant-manipulation-functions)