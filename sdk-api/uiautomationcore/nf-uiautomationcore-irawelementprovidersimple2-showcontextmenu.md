# IRawElementProviderSimple2::ShowContextMenu

## Description

Programmatically invokes a context menu on the target element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns an error code if the context menu could not be invoked.

 If no context menu is available directly on the element on which **ShowContextMenu** was invoked, the provider should attempt to invoke a context menu on the UI Automation parent of the current item.

## See also

[IRawElementProviderSimple2](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple2)