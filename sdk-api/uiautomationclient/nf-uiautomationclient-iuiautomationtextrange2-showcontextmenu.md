# IUIAutomationTextRange2::ShowContextMenu

## Description

Programmatically invokes a context menu on the target text range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns an error code if the context menu could not be invoked. If no context menu is available directly on the text range on which it was invoked, the Microsoft UI Automation system might attempt to invoke a context menu on the UI Automation parent of the current item.

The context menus themselves fire menu opened / closed events when they are invoked and dismissed.

## See also

[IUIAutomationTextRange2](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange2)

[Using Text Ranges](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-usingtextrangeobjects)