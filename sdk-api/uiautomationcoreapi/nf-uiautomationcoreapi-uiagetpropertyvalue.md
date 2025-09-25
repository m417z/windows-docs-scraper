# UiaGetPropertyValue function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves the value of a UI Automation property.

## Parameters

### `hnode` [in]

Type: **HUIANODE**

The element that the property is being requested from.

### `propertyId` [in]

Type: **PROPERTYID**

The property identifier. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `pValue` [out]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)***

Receives the value of the specified property, or the value returned by [UiaGetReservedNotSupportedValue](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiagetreservednotsupportedvalue) if the property is not supported.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.