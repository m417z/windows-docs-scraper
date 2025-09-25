# PropVariantToUInt16 function

## Description

Extracts a **unsigned short** value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value can be extracted, then a default value is assigned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `puiRet` [out]

Type: **USHORT***

When this function returns, contains the extracted property value if one exists; otherwise, 0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a **unsigned short** value. For instance, an application obtaining values from a property store can use this to safely extract the **unsigned short** value for UInt16 properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_UI2**, this helper function extracts the **unsigned short** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a USHORT. If a conversion is not possible, [PropVariantToUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint16) will return a failure code and set *puiRet* to 0. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, VT_EMPTY is successfully converted to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint16) to access a **unsigned short** value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;

// Assume variable ppropstore is initialized and valid

PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_FlagColor, &propvar);

if (SUCCEEDED(hr))

{

     // PKEY_FlagColor is expected to produce a VT_UI2 or VT_EMPTY value.

     // PropVariantToUInt16 will convert VT_EMPTY to 0.

     USHORT uColor;

     hr = PropVariantToUInt16(propvar, & uColor);

     if (SUCCEEDED(hr))

     {

             // uColor is now valid

     }

     else

     {

             // uColor is always 0

     }

     PropVariantClear(&propvar);

}
```

## See also

[InitPropVariantFromUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint16)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToUInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint16vector)

[VariantToUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint16)