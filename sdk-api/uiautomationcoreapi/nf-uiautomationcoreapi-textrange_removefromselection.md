# TextRange_RemoveFromSelection function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Removes the selected text, corresponding to the calling text range
*TextPatternRangeEndpoint_Start*
and *TextPatternRangeEndpoint_End*
endpoints, from an existing collection of selected text in a text container that supports multiple, disjoint selections.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

The text insertion point will move to the area of the new selection.

Providing a degenerate text range will move the text insertion point.