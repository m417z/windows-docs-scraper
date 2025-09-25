# IPropertyStoreCache::GetState

## Description

Gets the state of a specified property key.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `pstate` [out]

Type: **[PSC_STATE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-psc_state)***

A pointer to a [PSC_STATE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-psc_state) enumeration value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.