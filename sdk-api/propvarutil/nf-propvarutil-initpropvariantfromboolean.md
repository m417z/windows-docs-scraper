# InitPropVariantFromBoolean function

## Description

Initializes a given [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure as a **VT_BOOL** using a specified Boolean value.

## Parameters

### `fVal` [in]

Type: **BOOL**

Source **BOOL** value.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

Note that the *boolVal* member specifically initialized by this function is of type **VARIANT_BOOL** and therefore can have values **VARIANT_TRUE** or **VARIANT_FALSE**. When working with this structure member directly, use these constants instead of **TRUE** or **FALSE** because **VARIANT_TRUE** is not equal to **TRUE** and sizeof(**VARIANT_TRUE**) is not the same as sizeof(**TRUE**).

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromboolean).

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromBoolean(TRUE, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_BOOL.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromBooleanVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfrombooleanvector)

[InitVariantFromBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromboolean)

[PropVariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoboolean)