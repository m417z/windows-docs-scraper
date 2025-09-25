# ITextRangeProvider::ExpandToEnclosingUnit

## Description

Normalizes the text range by the specified text unit. The range is expanded if it is smaller than the specified unit, or shortened if it is
longer than the specified unit.

## Parameters

### `unit` [in]

Type: **[TextUnit](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textunit)**

The type of text units, such as character, word, paragraph, and so on.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Client applications such as screen readers use this method to retrieve the full word, sentence, or paragraph that exists at the insertion point or caret position.

Despite its name, the **ITextRangeProvider::ExpandToEnclosingUnit** method does not necessarily expand a text range. Instead, it "normalizes" a text range by moving the endpoints so that the range encompasses the specified text unit. The range is expanded if it is smaller than the specified unit, or shortened if it is longer than the specified unit. If the range is already an exact quantity of the specified units, it remains unchanged. It is critical that the **ExpandToEnclosingUnit** method always normalizes text ranges in a consistent manner; otherwise, other aspects of text range manipulation by text unit would be unpredictable. The following diagram shows how **ExpandToEnclosingUnit** normalizes a text range by moving the endpoints of the range.

![Diagram showing endpoint positions before and after a call to ExpandToEnclosingUnit](https://learn.microsoft.com/windows/win32/api/uiautomationcore/images/ExpandToEnclosingUnit.jpg)
**ExpandToEnclosingUnit** defaults to the next largest text unit
supported if the specified text unit is not supported by the control.
The order, from smallest unit to largest, is as follows:

* *Character*
* *Format*
* *Word*
* *Line*
* *Paragraph*
* *Page*
* *Document*

**ExpandToEnclosingUnit** respects both visible and hidden text.

### Range behavior when *unit* is `TextUnit::Format`

`TextUnit::Format` as a *unit* value positions the boundary of a text range to expand or move the range based on shared text attributes (format) of the text within the range. However, using the format text unit should not move or expand a text range across the boundary of an embedded object, such as an image or hyperlink. For more info, see [UI Automation Text Units](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-uiautomationtextunits) or [Text and TextRange Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingtextandtextrange).

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[Text and TextRange Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingtextandtextrange)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)