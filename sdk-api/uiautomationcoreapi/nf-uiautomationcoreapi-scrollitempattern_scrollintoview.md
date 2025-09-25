# ScrollItemPattern_ScrollIntoView function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Scrolls the content area of a container object in order to display the UI Automation element within the visible region (viewport) of the container.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The control pattern object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

This method does not guarantee the position of the UI Automation element
within the visible region (viewport) of the container.