# InitPropVariantVectorFromPropVariant function

## Description

Initializes a vector element in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure with a value stored in another **PROPVARIANT**.

## Parameters

### `propvarSingle` [in]

Type: **REFPROPVARIANT**

Reference to the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains a single value.

### `ppropvarVector` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is used to convert a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains a single value into a vector value.

For simple source types, this function initializes the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) as a vector of one element.

For a source that contains a string, this function initializes the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) with zero or more substrings taken from the source string, treating semicolons as delimiters. See [InitPropVariantFromStringAsVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringasvector) for more details.

The following input types are supported:

* VT_I2
* VT_UI2
* VT_I4
* VT_UI4
* VT_I8
* VT_UI8
* VT_R8
* VT_BOOL
* VT_DATE
* VT_FILETIME
* VT_BSTR
* VT_LPWSTR

Additional types may be supported in the future.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantVectorFromPropVariant](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantvectorfrompropvariant).

```cpp
// PROPVARIANT propvarSource;
// Assume propvarSource is initialized and valid.

if (PropVariantGetElementCount(propvarSource) == 1)
{
    PROPVARIANT propvar;

    HRESULT hr = InitPropVariantVectorFromPropVariant(propvarSource, &propvar);

    if (SUCCEEDED(hr))
    {
       // propvar now is valid and is either VT_EMPTY or contains a vector.
       PropVariantClear(&propvar);
    }
```

## See also

[InitPropVariantFromStringAsVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringasvector)

[PropVariantGetElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelem)

[PropVariantGetElementCount](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetelementcount)