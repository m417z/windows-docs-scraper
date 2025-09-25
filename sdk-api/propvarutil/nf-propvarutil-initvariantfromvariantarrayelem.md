# InitVariantFromVariantArrayElem function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with a value stored in another **VARIANT** structure.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `iElem` [in]

Type: **ULONG**

Index of one of the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure elements.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function works for [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structures of the following types:

* VT_BSTR
* VT_BOOL
* VT_I2
* VT_I4
* VT_I8
* VT_U12
* VT_U14
* VT_U18
* VT_DATE
* VT_ARRAY | (any one of VT_BSTR, VT_BOOL, VT_I2, VT_I4, VT_I8, VT_U12, VT_U14, VT_U18, VT_DATE)

Additional types may be supported in the future.

This function extracts a single value from the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure and uses that value to initialize the output **VARIANT** structure. The calling application must use [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) to free the **VARIANT** referred to by *pvar* when it is no longer needed.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is an array, *iElem* must be less than the number of elements in the array.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) has a single value, *iElem* must be 0.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is empty, this function always returns an error code.

You can use [VariantGetElementCount](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-variantgetelementcount) to obtain the number of elements in the array or array.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromVariantArrayElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromvariantarrayelem) in an iteration statement to access the values in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant).

```cpp
// VARIANT var;
// Assume var is initialized and valid.
UINT cElem = VariantGetElementCount(var);
HRESULT hr = <mark type="const">S_OK</mark>;

for (UINT iElem = 0; SUCCEEDED(hr) && iElem < cElem; iElem ++)
{
    VARIANT varElem = {0};

    hr = InitVariantFromVariantArrayElem(var, iElem, &varElem);

    if (SUCCEEDED(hr))
    {
        // varElem is now valid.
        VariantClear(&varElem);
    }
}
```

## See also

[InitPropVariantFromPropVariantVectorElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfrompropvariantvectorelem)

[VariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-variantgetelem)