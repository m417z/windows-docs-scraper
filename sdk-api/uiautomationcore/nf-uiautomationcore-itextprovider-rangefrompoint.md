# ITextProvider::RangeFromPoint

## Description

Returns the degenerate (empty) text range nearest to the specified screen coordinates.

## Parameters

### `point` [in]

Type: **[UiaPoint](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiapoint)**

The location in screen coordinates.

### `pRetVal` [out, retval]

Type: **[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)****

Receives a pointer to the degenerate (empty) text range
nearest the specified location. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A text range that encloses a child object is returned if the screen coordinates are
within the coordinates of an image, hyperlink, or other embedded object.

Because hidden text is not ignored by **ITextProvider::RangeFromPoint**, a degenerate range from the visible text
closest to the given point is returned.

The property never returns **NULL**.

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)