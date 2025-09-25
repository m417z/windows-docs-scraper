# PropVariantToUInt32 function

## Description

Extracts an **ULONG** value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value can be extracted, then a default value is assigned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

A reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pulRet` [out]

Type: **ULONG***

When this function returns, contains the extracted property value if one exists; otherwise, 0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a **ULONG** value. For instance, an application obtaining values from a property store can use this to safely extract the **ULONG** value for UInt32 properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_UI4**, this helper function extracts the **ULONG** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a **ULONG**. If a conversion is not possible, [PropVariantToUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32) will return a failure code and set *pulRet* to 0. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, **VT_EMPTY** is successfully converted to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32) to access a **ULONG** value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;

// Assume variable ppropstore is initialized and valid

PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_Rating, &propvar);

if (SUCCEEDED(hr))

{

     // PKEY_Rating is expected to produce a VT_UI4 or VT_EMPTY value.

     // PropVariantToUInt32 will convert VT_EMPTY to 0.

     ULONG uRating;

     hr = PropVariantToUInt32(propvar, &uRating);

     if (SUCCEEDED(hr))

     {

             // uRating is now valid

     }

     else

     {

             // uRating is always 0

     }

     PropVariantClear(&propvar);

}
```

## See also

[InitPropVariantFromUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint32)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToUInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32vector)

[VariantToUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint32)