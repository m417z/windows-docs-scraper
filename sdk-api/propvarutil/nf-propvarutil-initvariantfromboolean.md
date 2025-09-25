# InitVariantFromBoolean function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with a Boolean value.

## Parameters

### `fVal` [in]

Type: **BOOL**

Source **BOOL** value.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_BOOL variant.

Note that the **boolVal** structure member initialized by this function is of type **VARIANT_BOOL** and therefore can have values **VARIANT_TRUE** or **VARIANT_FALSE**. When you work with this structure member directly, use these constants instead of **TRUE** or **FALSE** because **VARIANT_TRUE** is not equal to **TRUE** and sizeof(VARIANT_TRUE) is not the same as sizeof(TRUE).

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromboolean).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromBoolean(TRUE, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_BOOL.
     VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromboolean)

[VariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoboolean)

[VariantToBooleanWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobooleanwithdefault)