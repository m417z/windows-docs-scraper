# InitPropVariantFromDouble function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a specified **double** value.

## Parameters

### `dblVal` [in]

Type: **DOUBLE**

The source **double** value.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_R8 propvariant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdouble).

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromDouble(3.1415, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_R8.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdoublevector)

[InitVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdouble)

[PropVariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodouble)

[PropVariantToDoubleWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublewithdefault)