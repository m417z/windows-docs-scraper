# IUIAutomationTextPattern::GetSelection

## Description

Retrieves a collection of text ranges that represents the currently selected text in a text-based control.

## Parameters

### `ranges` [out, retval]

Type: **[IUIAutomationTextRangeArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrangearray)****

Receives a pointer to the collection of text ranges.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the control supports the selection of multiple, non-contiguous spans of text, the *ranges* collection receives one text range for each selected span.

If the control contains only a single span of selected text, the *ranges* collection receives a single text range.

If the control contains a text insertion point but no text is selected, the *ranges* collection receives a degenerate (empty) text range at the position of the text insertion point.

If the control does not contain a text insertion point or does not support text selection, *ranges* is set to **NULL**.

Use the [IUIAutomationTextPattern::SupportedTextSelection](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextpattern-get_supportedtextselection) property to test whether a control supports text selection.

## See also

[IUIAutomationTextPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)