# FreePropVariantArray function

## Description

Frees the memory and references used by an array of [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures.

## Parameters

### `cVariants` [in]

Type: **ULONG**

The number of elements in the array specified by *rgvars*.

### `rgvars` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Array of [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures to free. When this function successfully returns, the **PROPVARIANT** structures in the array are zeroed and their type is set to VT_EMPTY.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function releases the memory and references held by each structure in the array before setting the structures to zero.

This function performs the same action as [ClearPropVariantArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-clearpropvariantarray), but returns an **HRESULT**.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [FreePropVariantArray](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-freepropvariantarray)

```cpp
// PROPVARIANT rgpropvar[5];
// Assume all 5 propvariants are initialized and valid.

FreePropVariantArray(ARRAYSIZE(rgpropvar), rgpropvar);
```