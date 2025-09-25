# IUIAutomationTextPattern::RangeFromPoint

## Description

Retrieves the degenerate (empty) text range nearest to the specified screen coordinates.

## Parameters

### `pt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A structure that contains the location, in screen coordinates.

### `range` [out, retval]

Type: **[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)****

Receives a pointer to the degenerate text range nearest the specified location.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A text range that wraps a child object is returned if the screen coordinates are within the coordinates of an image, hyperlink, Microsoft Excel spreadsheet, or other embedded object.

Because hidden text is not ignored, this method retrieves a degenerate range from the visible text closest to the specified coordinates.

The implementation of **RangeFromPoint** in Windows Internet Explorer 9 does not return the expected result. Instead, clients should:

1. Call the [GetVisibleRanges](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextpattern-getvisibleranges) method to retrieve an array of visible text ranges.
2. For each text range in the array, call [IUIAutomationTextRange::GetBoundingRectangles](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getboundingrectangles) to retrieve the bounding rectangles.
3. Check the bounding rectangles to find the text range that occupies the particular screen coordinates.

## See also

[IUIAutomationTextPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)