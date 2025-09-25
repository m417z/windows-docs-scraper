# LegacyIAccessiblePattern_GetIAccessible function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) object that corresponds to the UI Automation element.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

A control pattern object.

### `pAccessible` [out]

Type: **[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)****

The address of a variable that receives a pointer to an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface for the accessible object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.