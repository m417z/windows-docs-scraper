# IUIAutomationScrollPattern::SetScrollPercent

## Description

Sets the horizontal and vertical scroll positions as a percentage of the total content area within the UI Automation element.

## Parameters

### `horizontalPercent` [in]

Type: **double**

The percentage of the total horizontal content area, or **UIA_ScrollPatternNoScroll** if the horizontal position is not to be set.

### `verticalPercent` [in]

Type: **double**

The percentage of the total vertical content area, or **UIA_ScrollPatternNoScroll** if the vertical position is not to be set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is useful only when the content area of the control is larger than the visible region.

## See also

[IUIAutomationScrollPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationscrollpattern)

[IUIAutomationScrollPattern::Scroll](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationscrollpattern-scroll)