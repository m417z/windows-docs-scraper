# TextPattern_RangeFromPoint function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves the degenerate (empty) text range nearest to the specified screen coordinates.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

A control pattern object.

### `point` [in]

Type: **HiaPoint**

A [UiaPoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiapoint) structure that contains the location in screen coordinates.

### `pRetVal` [out]

Type: **HUIATEXTRANGE***

When this function returns, contains the text range that the node spans.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

A text range that wraps a child object is returned if the screen coordinates are within the coordinates of an image, hyperlink, Microsoft Excel spreadsheet, or other embedded object.

Because hidden text is not ignored, this method retrieves a degenerate range from the visible text closest to the specified coordinates.