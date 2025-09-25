# ClearPropVariantArray function

## Description

Frees the memory and references used by an array of [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures stored in an array.

## Parameters

### `rgPropVar` [in]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Array of [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures to free.

### `cVars` [in]

Type: **UINT**

The number of elements in the array specified by *rgPropVar*.

## Return value

No return value.

## Remarks

This function releases the memory and references held by each structure in the array before setting the structures to zero.

This function performs the same action as [FreePropVariantArray](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-freepropvariantarray), but **FreePropVariantArray** returns an **HRESULT**.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [ClearPropVariantArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-clearpropvariantarray)

```cpp
// PROPVARIANT rgpropvar[5];
// Assume all 5 propvariants are initialized and valid.

ClearPropVariantArray(rgpropvar, ARRAYSIZE(rgpropvar));
```

## See also

[ClearVariantArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-clearvariantarray)