# PropVariantToBoolean function

## Description

Extracts a Boolean property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value can be extracted, then a default value is assigned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pfRet` [out]

Type: **BOOL***

When this function returns, contains the extracted property value if one exists; otherwise, contains **FALSE**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a Boolean value. For instance, an application obtaining values from a property store can use this to safely extract the Boolean value for Boolean properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_BOOL**, this helper function extracts the Boolean value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a Boolean. If a conversion is not possible, [PropVariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoboolean) will return a failure code and set *pfRet* to **FALSE**. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, **VT_EMPTY** is successfully converted to **FALSE**.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoboolean) access a Boolean value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_IsShared, &propvar);
if (SUCCEEDED(hr))
{
     // PKEY_IsShared is expected to produce a VT_BOOL or VT_EMPTY value.
     // PropVariantToBoolean will convert VT_EMPTY to FALSE.
     BOOL fShared;

     hr = PropVariantToBoolean(propvar, &fShared);
     if (SUCCEEDED(hr))
     {
         // fShared is now valid
     }
     else
     {
         // fShared is always FALSE
     }

     PropVariantClear(&propvar);
}

```

## See also

[InitPropVariantFromBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromboolean)

[PropVariantGetBooleanElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetbooleanelem)

[PropVariantToBooleanWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobooleanwithdefault)

[VariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoboolean)