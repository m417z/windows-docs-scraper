# IUIAutomationTreeWalker::GetParentElement

## Description

Retrieves the parent element of the specified UI Automation element.

## Parameters

### `element` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the element for which to retrieve the parent.

### `parent` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the parent element, or **NULL** if there is no parent element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The structure of the Microsoft UI Automation tree changes as the visible UI elements on the desktop change. It is not guaranteed that an element returned as the parent element will be returned as the parent on subsequent passes.