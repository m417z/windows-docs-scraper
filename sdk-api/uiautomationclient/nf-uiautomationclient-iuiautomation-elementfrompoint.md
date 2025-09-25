# IUIAutomation::ElementFromPoint

## Description

Retrieves the UI Automation element at the specified point on the desktop.

## Parameters

### `pt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The desktop coordinates of the UI Automation element.

### `element` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the UI Automation element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **IUIAutomation::ElementFromPoint** method returns the [UIA_E_ELEMENTNOTAVAILABLE](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-error-codes) error code if the element under the point is already removed by the time the method returns. Clients should handle errors from this method gracefully; for example, by trying the call again.

## See also

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomation::ElementFromPointBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-elementfrompointbuildcache)