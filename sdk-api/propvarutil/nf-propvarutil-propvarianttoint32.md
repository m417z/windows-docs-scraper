# PropVariantToInt32 function

## Description

Extracts the **Int32** property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value can be extracted, then a default value is assigned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `plRet` [out]

Type: **LONG***

When this function returns, contains the extracted value if one exists; otherwise, 0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold an **Int32** value. For instance, an application obtaining values from a property store can use this to safely extract the **Int32** value for **Int32** properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_I4**, this helper function extracts the **long** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a **long**. If a conversion is not possible, [PropVariantToInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32) will return a failure code and set *plRet* to 0. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, **VT_EMPTY** is successfully converted to 0.

#### Examples

```cpp
// IPropertyStore *ppropstore;

// Assume variable ppropstore is initialized and valid

PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_FlagStatus, &propvar);

if (SUCCEEDED(hr))

{

     // PKEY_FlagStatus is expected to produce a VT_I4 or VT_EMPTY value.

     // PropVariantToInt32 will convert VT_EMPTY to 0.

     INT32 iStatus;

     hr = PropVariantToInt32(propvar, &iStatus);

     if (SUCCEEDED(hr))

     {

             // iStatus is now valid

     }

     else

     {

             // iStatus is always 0

     }

     PropVariantClear(&propvar);

}
```

## See also

[InitPropVariantFromInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint32)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32vector)

[VariantToInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint32)