# IPropertyStoreCache::GetValueAndState

## Description

Gets value and state data for a property key.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure identifying the property.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure for the property data.

### `pstate` [out]

Type: **[PSC_STATE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-psc_state)***

A pointer to a [PSC_STATE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-psc_state) enumeration value declaring the current state of the property.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.