# PropVariantGetUInt64Elem function

## Description

Extracts a single unsigned Int64 element from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure of type VT_UI8, VT_VECTOR | VT_UI8, or VT_ARRAY | VT_UI8.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `iElem` [in]

Type: **ULONG**

The vector or array index; otherwise, *iElem* must be 0.

### `pnVal` [out]

Type: **ULONGLONG***

When this function returns, contains the extracted Int64 value.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function works for [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures of the following types:

* VT_UI8
* VT_VECTOR | VT_UI8
* VT_ARRAY | VT_UI8

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_UI8, *iElem* must be 0. Otherwise *iElem* must be less than the number of elements in the vector or array. You can use [PropVariantGetElementCount](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelementcount) to obtain the number of elements in the vector or array.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantGetUInt64Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetuint64elem) with an iteration statement to access the values in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid

if ((propvar.vt & VT_TYPEMASK) == VT_UI8)
{
    UINT cElem = PropVariantGetElementCount(propvar);
    HRESULT hr = <mark type="const">S_OK</mark>;

    for (UINT iElem = 0; SUCCEEDED(hr) && iElem < cElem; iElem ++)
    {
        ULONGLONG nValue;
        hr = PropVariantGetUInt64Elem(propvar, iElem, &nValue);

        if (SUCCEEDED(hr))
        {
            // nValue is valid now
        }
    }
}
```

## See also

[PropVariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelem)