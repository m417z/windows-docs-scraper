# PSPropertyBag_WritePropertyKey function

## Description

Sets the property key value of a property in a property bag.

## Parameters

### `propBag` [in]

Type: **[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag)***

A pointer to an [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) object that represents the property bag in which the property is stored.

### `propName` [in]

Type: **LPCWSTR**

A null-terminated property name string.

### `value` [in]

Type: **REFPROPERTYKEY**

A [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that specifies the property key value to store in the property.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Property keys uniquely identify a property. For example, `PKEY_Keywords` corresponds to `System.Keywords`. This function succeeds only for properties registered as part of the property schema.

The property bag property function API converts between window types and the **VARIANT** type that is used to express values in a property bag. Doing so eases property bag usage, simplifies applications, and avoids common coding errors.

## See also

[PSPropertyBag_ReadPropertyKey](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertybag_readpropertykey)