# LegacyIAccessiblePattern_SetValue function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Sets the Microsoft Active Accessibility value property for the node.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The *control pattern* object.

### `szValue` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A localized string that contains the value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.