# IUIAutomationTextPattern::GetVisibleRanges

## Description

Retrieves an array of disjoint text ranges from a text-based control where each text range represents a contiguous span of visible text.

## Parameters

### `ranges` [out, retval]

Type: **[IUIAutomationTextRangeArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrangearray)****

Receives a pointer to the collection of visible text ranges within the text-based control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the visible text consists of one contiguous span of text, the *ranges* array will contain a single text range that represents all of the visible text.

If the visible text consists of multiple, disjoint spans of text, the *ranges* array will contain one text range for each visible span, beginning with the first visible span, and ending with the last visible span. Disjoint spans of visible text can occur when the content of a text-based control is partially obscured
by an overlapping window or other object, or when a text-based control with multiple pages or columns
has content that is partially scrolled out of view.

**IUIAutomationTextPattern::GetVisibleRanges** retrieves a degenerate (empty) text range if no text is visible, if all text is scrolled out of view, or if the text-based control contains no text.

## See also

[IUIAutomationTextPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)