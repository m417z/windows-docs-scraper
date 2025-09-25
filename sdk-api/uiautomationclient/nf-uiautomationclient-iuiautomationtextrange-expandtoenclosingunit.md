# IUIAutomationTextRange::ExpandToEnclosingUnit

## Description

Normalizes the text range by the specified text unit. The range is expanded if it is smaller than the specified unit, or shortened if it is longer than the specified unit.

## Parameters

### `textUnit` [in]

Type: **[TextUnit](https://learn.microsoft.com/windows/win32/api/uiautomationcore/ne-uiautomationcore-textunit)**

The text unit, such as line or paragraph.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

Client applications such as screen readers use this method to retrieve the full word, sentence, or paragraph that exists at the insertion point or caret position.

Despite its name, the ExpandToEnclosingUnit method does not necessarily expand a text range. Instead, it "normalizes" a text range by moving the endpoints so that the range encompasses the specified text unit. The range is expanded if it is smaller than the specified unit, or shortened if it is longer than the specified unit. If the range is already an exact quantity of the specified units, it remains unchanged. The following diagram shows how ExpandToEnclosingUnit normalizes a text range by moving the endpoints of the range.

![Diagram showing endpoints before and after ExpandToEnclosingUnit](https://learn.microsoft.com/windows/win32/api/uiautomationclient/images/ExpandToEnclosingUnit.jpg)

*Diagram showing endpoints before and after ExpandToEnclosingUnit*

ExpandToEnclosingUnit defaults to the next largest text unit supported if the specified text unit is not supported by the control.

The order, from smallest unit to largest, is as follows:

- Character
- Format
- Word
- Line
- Paragraph
- Page
- Document

ExpandToEnclosingUnit respects both visible and hidden text.

### Range behavior when *unit* is `TextUnit::Format`

`TextUnit::Format`, as a *unit* value, positions the boundary of a text range to expand or move the range based on shared text attributes (or format) of the text within the range. However, the `Format` text unit does not move or expand a text range across the boundary of an embedded object, such as an image or hyperlink. For more info, see [UI Automation Text Units](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-uiautomationtextunits) or [UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview).

## See also

[IUIAutomationTextRange interface](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange), [UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)