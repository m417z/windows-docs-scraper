# PropVariantGetDoubleElem function

## Description

Extracts a single **double** element from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure of type `VT_R8`, `VT_VECTOR | VT_R8`, or `VT_ARRAY | VT_R8`.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `iElem` [in]

Type: **ULONG**

Specifies vector or array index; otherwise, *iElem* must be 0.

### `pnVal` [out]

Type: **DOUBLE***

When this function returns, contains the extracted double value.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type `VT_R8`, *iElem* must be 0. Otherwise *iElem* must be less than the number of elements in the vector or array. You can use [PropVariantGetElementCount](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelementcount) to obtain the number of elements in the vector or array.

The following example uses this function to loop through the values in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

#### Examples

```cpp
// PROPVARIANT propvar;
// assume propvar is initialized and valid

if ((propvar.vt & VT_TYPEMASK) == VT_R8)
{
    UINT cElem = PropVariantGetElementCount(propvar);
    HRESULT hr = <mark type="const">S_OK</mark>;

    for (UINT iElem = 0; SUCCEEDED(hr) && iElem < cElem; iElem ++)
    {
        DOUBLE nValue;
        hr = PropVariantGetDoubleElem(propvar, iElem, &nValue);

        if (SUCCEEDED(hr))
        {
            // nValue is valid now
        }
    }
}
```

## See also

[PropVariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelem)