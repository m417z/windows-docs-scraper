# IUIAutomationScrollPattern::Scroll

## Description

Scrolls the visible region of the content area horizontally and vertically.

## Parameters

### `horizontalAmount` [in]

Type: **[ScrollAmount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-scrollamount)**

A value indicating the size of the horizontal scroll increment, or **UIA_ScrollPatternNoScroll** if the horizontal position is not to be set.

### `verticalAmount` [in]

Type: **[ScrollAmount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-scrollamount)**

A value from the [ScrollAmount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-scrollamount) enumerated type indicating the size of the vertical scroll increment, or **UIA_ScrollPatternNoScroll** if the vertical position is not to be set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationScrollPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationscrollpattern)

[IUIAutomationScrollPattern::SetScrollPercent](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationscrollpattern-setscrollpercent)