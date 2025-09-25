# VariantCopyInd function

## Description

Frees the destination variant and makes a copy of the source variant, performing the necessary indirection if the source is specified to be VT_BYREF.

## Parameters

### `pvarDest` [out]

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

This function is useful when a copy of a variant is needed, and to guarantee that it is not VT_BYREF, such as when handling arguments in an implementation of [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).

For example, if the source is a (VT_BYREF | VT_I2), the destination will be a BYVAL | VT_I2. The same is true for all legal VT_BYREF combinations, including VT_VARIANT.

If pvargSrc is (VT_BYREF | VT_VARIANT), and the contained variant is VT_BYREF, the contained variant is also dereferenced.

This function frees any existing contents of pvarDest.

## See also

[Variant Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/variant-manipulation-functions)