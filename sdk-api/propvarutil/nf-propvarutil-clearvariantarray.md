# ClearVariantArray function

## Description

Frees the memory and references used by an array of [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structures stored in an array.

## Parameters

### `pvars` [in]

Type: **VARIANT***

Array of [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structures to free.

### `cvars` [in]

Type: **UINT**

The number of elements in the array specified by *pvars*.

## Return value

No return value.

## Remarks

This function releases the memory and references held by each structure in the array before it sets the structures to zero.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [ClearVariantArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-clearvariantarray)

```cpp
// VARIANT rgpropvar[5];
// Assume all 5 variants are initialized and valid.

ClearVariantArray(rgpropvar, ARRAYSIZE(rgpropvar));
```

## See also

[ClearPropVariantArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-clearpropvariantarray)

[FreePropVariantArray](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-freepropvariantarray)