# PropVariantToUInt64 function

## Description

Extracts a **UInt64** value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value can be extracted, then a default value is assigned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pullRet` [out]

Type: **ULONGLONG***

When this function returns, contains the extracted property value if one exists; otherwise, 0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a **ULONGLONG** value. For instance, an application obtaining values from a property store can use this to safely extract the **ULONGLONG** value for **UInt64** properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_UI8**, this helper function extracts the **ULONGLONG** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a **ULONGLONG**. If a conversion is not possible, [PropVariantToUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64) will return a failure code and set *pullRet* to 0. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, **VT_EMPTY** is successfully converted to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64) to access a **ULONGLONG** value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;

// Assume variable ppropstore is initialized and valid

PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_Size, &propvar);

if (SUCCEEDED(hr))

{

     // PKEY_Size is expected to produce a VT_UI8 or VT_EMPTY value.

     // PropVariantToUInt64 will convert VT_EMPTY to 0.

     ULONGLONG ullSize;

     hr = PropVariantToUInt64(propvar, &ullSize);

     if (SUCCEEDED(hr))

     {

             // ullSize is now valid

     }

     else

     {

             // ullSize is always 0

     }

     PropVariantClear(&propvar);

}
```

## See also

[InitPropVariantFromUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint64)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToUInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64vector)

[VariantToUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint64)