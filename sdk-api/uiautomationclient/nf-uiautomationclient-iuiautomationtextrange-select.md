# IUIAutomationTextRange::Select

## Description

Selects the span of text that corresponds to this text range, and removes any previous selection.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the **Select** method is called on a text range object that represents a degenerate (empty) text range, the text insertion point moves to the starting endpoint of the text range.

## See also

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

[IUIAutomationTextRange::AddToSelection](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-addtoselection)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)