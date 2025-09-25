# InitVariantFromDouble function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with a value of type DOUBLE.

## Parameters

### `dblVal` [in]

Type: **DOUBLE**

Source value.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_R8 variant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdouble).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromDouble(3.1415, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_R8.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdouble)

[VariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodouble)

[VariantToDoubleWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublewithdefault)