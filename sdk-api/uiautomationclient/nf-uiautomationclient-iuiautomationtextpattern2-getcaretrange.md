# IUIAutomationTextPattern2::GetCaretRange

## Description

Retrieves a zero-length text range at the location of the caret that belongs to the text-based control.

## Parameters

### `isActive` [out, retval]

Type: **BOOL***

**TRUE** if the text-based control that contains the caret has keyboard focus, otherwise **FALSE**.

### `range` [out, retval]

Type: **[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)****

Receives a text range that represents the current location of the caret that belongs to the text-based control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the *isActive* parameter is **FALSE**, the caret that belongs to the text-based control might not be at the same location as the system caret.

This method retrieves a text range that a client can use to find the bounding rectangle of the caret belonging to the text-based control, or to find the text near the caret.

## See also

[IUIAutomationTextPattern2](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern2)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)

[Working with Text-based Controls](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithtextbasedcontrols)