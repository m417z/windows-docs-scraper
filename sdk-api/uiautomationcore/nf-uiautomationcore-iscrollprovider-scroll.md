# IScrollProvider::Scroll

## Description

Scrolls the visible region of the content area horizontally and vertically.

## Parameters

### `horizontalAmount` [in]

Type: **[ScrollAmount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-scrollamount)**

The horizontal scrolling increment that is specific to the control.

### `verticalAmount` [in]

Type: **[ScrollAmount](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-scrollamount)**

The vertical scrolling increment that is specific to the control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

**Conceptual**

[IScrollProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iscrollprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)