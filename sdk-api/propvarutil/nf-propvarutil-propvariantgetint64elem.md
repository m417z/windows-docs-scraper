# PropVariantGetInt64Elem function

## Description

Extracts a single Int64 element from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure of type VT_I8, VT_VECTOR | VT_I8, or VT_ARRAY | VT_I8.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `iElem` [in]

Type: **ULONG**

The vector or array index; otherwise, *iElem* must be 0.

### `pnVal` [out]

Type: **LONGLONG***

When this function returns, contains the extracted Int64 value.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function works for[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures of the following types:

* VT_I8
* VT_VECTOR | VT_I8
* VT_ARRAY | VT_I8

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_I8, *iElem* must be 0. Otherwise, *iElem* must be less than the number of elements in the vector or array. You can use [PropVariantGetElementCount](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelementcount) to obtain the number of elements in the vector or array.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantGetInt64Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetint64elem) with an iteration statement to access the values in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume propvar is initialized and valid;

if ((propvar.vt & VT_TYPEMASK) == VT_I8)
{
    UINT cElem = PropVariantGetElementCount(propvar);
    HRESULT hr = <mark type="const">S_OK</mark>;

    for (UINT iElem = 0; SUCCEEDED(hr) && iElem < cElem; iElem ++)
    {
        LONGLONG nValue;
        hr = PropVariantGetInt64Elem(propvar, iElem, &nValue);

        if (SUCCEEDED(hr))
        {
            // nValue is valid now
        }
    }
}
```

## See also

[PropVariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelem)