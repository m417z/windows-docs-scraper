# PropVariantGetFileTimeElem function

## Description

Extracts a single [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) element from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure of type VT_FILETIME, VT_VECTOR | VT_FILETIME, or VT_ARRAY | VT_FILETIME.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `iElem` [in]

Type: **ULONG**

Specifies vector or array index; otherwise, this value must be 0.

### `pftVal` [out]

Type: **FILETIME***

When this function returns, contains the extracted filetime value.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_FILETIME, *iElem* must be 0; otherwise, *iElem* must be less than the number of elements in the vector or array. You can use [PropVariantGetElementCount](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelementcount) to obtain the number of elements in the vector or array.

#### Examples

The following code example, to be included as part of a larger program, demonstrates how to use [PropVariantGetFileTimeElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetfiletimeelem) in an iteration statement to access the values in [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume propvar is initialized and valid;

if ((propvar.vt & VT_TYPEMASK) == VT_FILETIME)
{
    UINT cElem = PropVariantGetElementCount(propvar);
    HRESULT hr = <mark type="const">S_OK</mark>;

    for (UINT iElem = 0; SUCCEEDED(hr) && iElem < cElem; iElem ++)
    {
        FILETIME ftValue;
        hr = PropVariantGetFileTimeElem(propvar, iElem, &ftValue);

        if (SUCCEEDED(hr))
        {
            // ftValue is valid now
        }
    }
}
```

## See also

[PropVariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelem)