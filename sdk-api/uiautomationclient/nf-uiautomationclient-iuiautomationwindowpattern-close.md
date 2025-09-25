# IUIAutomationWindowPattern::Close

## Description

Closes the window.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When called on a split pane control, this method closes the pane and removes the associated split. This method may also close all other panes, depending on implementation.

## See also

[IUIAutomationWindowPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationwindowpattern)