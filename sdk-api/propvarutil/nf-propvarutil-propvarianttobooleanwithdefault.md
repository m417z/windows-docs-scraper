# PropVariantToBooleanWithDefault function

## Description

Extracts the Boolean property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value exists, then the specified default value is returned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `fDefault` [in]

Type: **BOOL**

Specifies the default property value, for use where no value currently exists.

## Return value

Type: **BOOL**

The extracted Boolean value or the default value.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a Boolean value and would like to use a default value if it does not. For instance, an application that obtains values from a property store can use this to safely extract the Boolean value for Boolean properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_BOOL**, this helper function extracts the Boolean value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a Boolean. If the source **PROPVARIANT** has type **VT_EMPTY** or a conversion is not possible, then [PropVariantToBooleanWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobooleanwithdefault) returns the default provided by *fDefault*. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToBooleanWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobooleanwithdefault) to access a Boolean value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume the variable ppropstore is initialized and valid.
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_IsRead, &propvar);

if (SUCCEEDED(hr))
{
     // PKEY_IsRead is expected to produce a VT_BOOL or VT_EMPTY value.
     // The application developer decided to treat VT_EMPTY or invalid values as TRUE
     BOOL fShared = PropVariantToBooleanWithDefault(propvar, TRUE);

     // fShared is now valid.
     PropVariantClear(&propvar);
}
```