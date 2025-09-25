# ScrollPattern_Scroll function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Scrolls the currently visible region of the content area the specified [ScrollAmount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-scrollamount), horizontally,
vertically, or both.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The control pattern object.

### `horizontalAmount` [in]

Type: **[ScrollAmount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-scrollamount)**

The amount to scroll the container on the horizontal axis, as a percentage.

### `verticalAmount` [in]

Type: **[ScrollAmount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-scrollamount)**

The amount to scroll the container on the vertical axis, as a percentage.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.