# IPropertyStoreCache::SetValueAndState

## Description

Sets value and state data for a property key.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure identifying the property.

### `ppropvar` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure containing the property data.

### `state` [in]

Type: **[PSC_STATE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-psc_state)**

A value from the [PSC_STATE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-psc_state) enumeration declaring the state of the property.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.