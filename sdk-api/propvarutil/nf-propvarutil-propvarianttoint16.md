# PropVariantToInt16 function

## Description

Extracts an Int16 property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `piRet` [out]

Type: **SHORT***

When this function returns, contains the extracted property value if one exists; otherwise, 0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold an Int16 value. For instance, an application obtaining values from a property store can use this to safely extract the Int16 value for Int16 properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_I2**, this helper function extracts the Int16 value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into an Int16. If a conversion is not possible, [PropVariantToInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16) will return a failure code and set *piRet* to 0. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, VT_EMPTY is successfully converted to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16) to access an Int16 value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;

// Assume variable ppropstore is initialized and valid

PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_Image_ResolutionUnit, &propvar);

if (SUCCEEDED(hr))

{

     // PKEY_Image_ResolutionUnit is expected to produce a VT_I2 or VT_EMPTY value.

     // PropVariantToInt16 will convert VT_EMPTY to 0.

     INT16 iUnit;

     hr = PropVariantToInt16(propvar, & iUnit);

     if (SUCCEEDED(hr))

     {

             // iUnit is now valid

     }

     else

     {

             // iUnit is always 0

     }

     PropVariantClear(&propvar);

}
```