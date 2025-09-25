# IUIAutomationElement::GetClickablePoint

## Description

Retrieves a point on the element that can be clicked.

## Parameters

### `clickable` [out]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

Receives the physical screen coordinates of a point that can be used by a client to click this element.

### `gotClickable` [out, retval]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Receives **TRUE** if a clickable point was retrieved, or **FALSE** otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A client application can use this method to simulate clicking the left or right mouse button. For example, to simulate clicking the right mouse button to display the context menu for a control:

* Call the **GetClickablePoint** method to find a clickable point on the control.
* Call the [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput) function to send a right-mouse-down, right-mouse-up sequence.

## See also

[Automation Element Property IDs](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-automation-element-propids)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

**Reference**