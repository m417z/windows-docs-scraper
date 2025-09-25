# VariantCompare function

## Description

Compares two variant structures, based on default comparison rules.

## Parameters

### `var1` [in]

Type: **REFVARIANT**

Reference to a first variant structure.

### `var2` [in]

Type: **REFVARIANT**

Reference to a second variant structure.

## Return value

Type: **INT**

* Returns 1 if *var1* is greater than *var2*
* Returns 0 if *var1* equals *var2*
* Returns -1 if *var1* is less than *var2*

## Remarks

**Note** This function does not support the comparison of different VARIANT types. If the types named in *var1* and *var2* are different, the results are undefined and should be ignored. Calling applications should ensure that they are comparing two of the same type before they call this function. The [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) function can be used to convert the two structures to the same type.

By default, VT_NULL / VT_EMPTY / 0-element vectors are considered to be less than any other vartype.