# IUIAutomationTextRange::AddToSelection

## Description

Adds the text range to the collection of selected text ranges in a control that supports multiple, disjoint spans of selected text.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The text insertion point moves to the newly selected text. If **AddToSelection** is called on a text range object that represents a degenerate (empty) text range, the text insertion point moves to the starting endpoint of the text range.

## See also

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

[IUIAutomationTextRange::Select](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-select)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)