# PropVariantGetBooleanElem function

## Description

Extracts a single Boolean element from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure of type `VT_BOOL`, `VT_VECTOR | VT_BOOL`, or `VT_ARRAY | VT_BOOL`.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

A reference to the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `iElem` [in]

Type: **ULONG**

Specifies the vector or array index; otherwise, *iElem* must be 0.

### `pfVal` [out]

Type: **BOOL***

When this function returns, contains the extracted Boolean value.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure has type `VT_BOOL`, *iElem* must be 0. Otherwise *iElem* must be less than the number of elements in the vector or array. You can use [PropVariantGetElementCount](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelementcount) to obtain the number of elements in the vector or array.

The following example uses this function to loop through the values in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

#### Examples

```cpp
// PROPVARIANT propvar;
// assume propvar is initialized and valid

if ((propvar.vt & VT_TYPEMASK) == VT_BOOL)
{
    UINT cElem = PropVariantGetElementCount(propvar);
    HRESULT hr = <mark type="const">S_OK</mark>;

    for (UINT iElem = 0; SUCCEEDED(hr) && iElem < cElem; iElem ++)
    {
        BOOL fValue;
        hr = PropVariantGetBooleanElem(propvar, iElem, &fValue);

        if (SUCCEEDED(hr))
        {
            // fValue is valid now
        }
    }
}
```

## See also

[PropVariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelem)