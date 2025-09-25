# ITextRangeProvider::Move

## Description

Moves the text range forward or backward by the specified number of text units.

## Parameters

### `unit` [in]

Type: **[TextUnit](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textunit)**

The type of text units, such as character, word, paragraph, and so on.

### `count` [in]

Type: **int**

The number of text units to move. A positive value moves the text range forward.

A negative value moves the text range backward. Zero has no effect.

### `pRetVal` [out, retval]

Type: **int***

The number of text units actually moved. This can be less than the number requested if either of the new text range endpoints is greater than or less than the endpoints retrieved by the [ITextProvider::DocumentRange](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-itextprovider-get_documentrange) method. This value can be negative if navigation is happening in the backward direction.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**ITextRangeProvider::Move** should only move the text range to span a different part of the text, it should not alter the text in any way.

For a non-degenerate (non-empty) text range, **ITextRangeProvider::Move** should normalize and move the text range by performing the following steps.

1. Collapse the text range to a degenerate (empty) range at the starting endpoint.
2. If necessary, move the resulting text range backward in the document to the beginning of the requested unit boundary.
3. Move the text range forward or backward in the document by the requested number of text unit boundaries.
4. Expand the text range from the degenerate state by moving the ending endpoint forward by one requested text unit boundary.

If any of the preceding steps fail, the text range should be left unchanged. If the text range cannot be moved as far as the requested number of text units, but can be moved by a smaller number of text units, the text range should be moved by the smaller number of text units and *pRetVal* should be set to the number of text units moved successfully.

For a degenerate text range, **ITextRangeProvider::Move** should simply move the text insertion point by the specified number of text units.

When moving a text range, the provider should ignore the boundaries of any embedded objects in the text.

**ITextRangeProvider::Move** should respect both hidden and visible text.

If a text-based control does not support the text unit specified by the *unit* parameter, the provider should substitute the next larger supported text unit.
The size of the text units, from smallest unit to largest, is as follows.

* Character
* Format
* Word
* Line
* Paragraph
* Page
* Document

### Range behavior when *unit* is `TextUnit::Format`

`TextUnit::Format` as a *unit* value positions the boundary of a text range to expand or move the range based on shared text attributes (format) of the text within the range. However, using the format text unit should not move or expand a text range across the boundary of an embedded object, such as an image or hyperlink. For more info, see [UI Automation Text Units](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-uiautomationtextunits) or [Text and TextRange Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingtextandtextrange).

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[Text and TextRange Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingtextandtextrange)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)