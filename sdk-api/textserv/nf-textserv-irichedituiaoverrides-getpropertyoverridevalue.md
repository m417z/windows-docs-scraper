# IRicheditUiaOverrides::GetPropertyOverrideValue

## Description

Retrieves the host container's override value for the specified Microsoft UI Automation accessibility property of a windowless rich edit control.

## Parameters

### `propertyId`

Type: **PROPERTYID**

The identifier of the property to retrieve.

### `pRetValue`

Type: **VARIANT***

The host container's override value for the *propertyId* property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRicheditUiaOverrides](https://learn.microsoft.com/windows/desktop/api/textserv/nn-textserv-irichedituiaoverrides)