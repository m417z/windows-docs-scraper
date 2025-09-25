# IUIAutomation::GetFocusedElement

## Description

Retrieves the UI Automation element that has the input focus.

## Parameters

### `element` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the UI Automation element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **IUIAutomation::GetFocusedElement** method returns the [UIA_E_ELEMENTNOTAVAILABLE](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-error-codes) error code if the focused element is already removed by the time the method returns. Clients should handle errors from this method gracefully; for example, by trying the call again.