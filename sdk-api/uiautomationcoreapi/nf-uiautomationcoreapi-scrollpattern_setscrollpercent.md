# ScrollPattern_SetScrollPercent function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Scrolls a container to a specific position horizontally, vertically, or both.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The control pattern object.

### `horizontalPercent` [in]

Type: **double**

The horizontal position to scroll to.

### `verticalPercent` [in]

Type: **double**

The vertical position to scroll to.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

The scroll area is normalized to range from 0.0 to 100.0. If the position is set to 0.0, the control
scrolls to the beginning of the
visible region, and if the position is set to 100.0, it scrolls to the end of the visible region.
Pass -1.0 for the percent parameters if no scrolling occurs on that axis.