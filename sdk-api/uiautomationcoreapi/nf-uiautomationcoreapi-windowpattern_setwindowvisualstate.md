# WindowPattern_SetWindowVisualState function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Sets the visual state of a window; for example, to maximize a window.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The control pattern object.

### `state` [in]

Type: **[WindowVisualState](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-windowvisualstate)**

The visual state to set the window to.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.