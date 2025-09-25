# IScrollProvider::SetScrollPercent

## Description

Sets the horizontal and vertical scroll position as a percentage of the total content area within the control.

## Parameters

### `horizontalPercent` [in]

Type: **double**

The horizontal position as a percentage of the content area's total range, or **UIA_ScrollPatternNoScroll** if there is no horizontal scrolling.

### `verticalPercent` [in]

Type: **double**

The vertical position as a percentage of the content area's total range, or **UIA_ScrollPatternNoScroll** if there is no vertical scrolling.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is only useful when the content area of the control is
larger than the visible region.

## See also

[IScrollProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iscrollprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)