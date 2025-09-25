# IUIAutomationElement3::ShowContextMenu

## Description

Programmatically invokes a context menu on the target element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns an error code if the context menu could not be invoked. If no context menu is available directly on the element on which it was invoked, calling this method might invoke a context menu on the Microsoft UI Automation parent of the current item.

The context menus themselves fire menu opened / closed events when they are invoked and dismissed.

## See also

[IUIAutomationElement3](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement3)