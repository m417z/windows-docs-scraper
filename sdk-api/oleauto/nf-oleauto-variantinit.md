# VariantInit function

## Description

Initializes a variant.

## Parameters

### `pvarg` [out]

The variant to initialize.

## Remarks

The **VariantInit** function initializes the VARIANTARG by setting the **vt** field to VT_EMPTY. Unlike [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear), this function does not interpret the current contents of the VARIANTARG. Use **VariantInit** to initialize new local variables of type VARIANTARG (or VARIANT).

#### Examples

The following example shows how to initialize an array of variants, where `celt` is the number of elements in the array.

```cpp
for(int i = 0; i < celt; ++i)
   VariantInit(&rgvar[i]);
```

## See also

[Variant Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/variant-manipulation-functions)