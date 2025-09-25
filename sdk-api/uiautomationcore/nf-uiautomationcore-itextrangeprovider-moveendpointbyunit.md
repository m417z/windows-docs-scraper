# ITextRangeProvider::MoveEndpointByUnit

## Description

Moves one endpoint of the text range the specified number of [TextUnit](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textunit) units within the document range.

## Parameters

### `endpoint` [in]

Type: **TextPatternRangeEndpoint**

The endpoint to move.

### `unit` [in]

Type: **[TextUnit](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textunit)**

The type of text units, such as character, word, paragraph, and so on.

### `count` [in]

Type: **int**

The number of units to move. A positive value moves the endpoint forward.
A negative value moves backward. A value of 0 has no effect.

### `pRetVal` [out, retval]

Type: **int***

Receives the number of units actually moved, which can be less than the number requested if moving the endpoint runs into the beginning or end of the document.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [endpoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textpatternrangeendpoint) is moved forward or backward, as specified, to the next available unit boundary. If the original **endpoint** was at the boundary of the specified text unit, the **endpoint** is moved to the next available text unit boundary, as shown in the following illustration.

![Illustration showing endpoints of a text range moving](https://learn.microsoft.com/windows/win32/api/uiautomationcore/images/MoveEndpointByUnit.gif)
If the [endpoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textpatternrangeendpoint) being moved crosses the other **endpoint** of the same text range, the other **endpoint** is also moved, resulting in a degenerate range and ensuring the correct ordering of the **endpoint** (that is, that the start is always less than or equal to the end).

**ITextRangeProvider::MoveEndpointByUnit** deprecates up to the next supported text unit if the given text unit is not supported by the control.

The order, from smallest unit to largest, is listed here.

* *Character*
* *Format*
* *Word*
* *Line*
* *Paragraph*
* *Page*
* *Document*

### Range behavior when *unit* is `TextUnit::Format`

`TextUnit::Format` as a *unit* value positions the boundary of a text range to expand or move the range based on shared text attributes (format) of the text within the range. However, using the format text unit should not move or expand a text range across the boundary of an embedded object, such as an image or hyperlink. For more info, see [UI Automation Text Units](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-uiautomationtextunits) or [Text and TextRange Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingtextandtextrange).

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[Text and TextRange Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingtextandtextrange)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)