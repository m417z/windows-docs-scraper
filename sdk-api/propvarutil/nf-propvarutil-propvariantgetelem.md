# PropVariantGetElem function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a specified element in another **PROPVARIANT** structure.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `iElem` [in]

Type: **ULONG**

Index of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure element in *propvarIn*.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) with the value specified from the source **PROPVARIANT** structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function works for [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures of the following types:

* VT_LPWSTR
* VT_BSTR
* VT_BOOL
* VT_I2
* VT_I4
* VT_I8
* VT_U12
* VT_U14
* VT_U18
* VT_FILETIME
* VT_VECTOR | (any one of VT_LPWSTR, VT_BSTR, VT_BOOL, VT_I2, VT_I4, VT_I8, VT_U12, VT_U14, VT_U18, VT_FILETIME)
* VT_ARRAY | (any one of VT_BSTR, VT_BOOL, VT_I2, VT_I4, VT_I8, VT_U12, VT_U14, VT_U18)

Additional types may be supported in the future.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

This function extracts a single value from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure and uses that value to initialize the output **PROPVARIANT** structure. The calling application must use [PropVariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-imimeallocator-propvariantclear) to free the **PROPVARIANT** referred to by *ppropvar* when it is no longer needed.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is a vector or array, *iElem* must be less than the number of elements in the vector or array.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has only a single value, *iElem* must be 0.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is empty, this function always returns an error code.

**Note** You can use [PropVariantGetElementCount](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelementcount) to obtain the number of elements in the vector or array.

#### Examples

The following code example, to be included as part of a larger program, demonstrates how to use [PropVariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelem) in an iteration statement to access the values in [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume propvar is initialized and valid.

UINT cElem = PropVariantGetElementCount(propvar);
HRESULT hr = <mark type="const">S_OK</mark>;

for (UINT iElem = 0; SUCCEEDED(hr) && iElem < cElem; iElem ++)
{
   <xref rid="_stg_propvariant"/>propvarElem = {0};

    hr = PropVariantGetElem(propvar, iElem, &propvarElem);

    if (SUCCEEDED(hr))
    {
        // propvarElem is valid now.
        PropVariantClear(&propvarElem);
    }
}
```

## See also

[InitPropVariantFromPropVariantVectorElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfrompropvariantvectorelem)