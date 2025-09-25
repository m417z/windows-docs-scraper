# ItemContainerPattern_FindItemByProperty function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves a node within a containing node, based on a specified property value.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The *control pattern* object.

### `hnodeStartAfter` [in]

Type: **HUIANODE**

The node after which to start the search.

### `propertyId` [in]

Type: **PROPERTYID**

The property identifier. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `value` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)**

The value of the *propertyId* property.

### `pFound` [out]

Type: **HUIANODE***

The node of the matching element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.