# ITextRangeProvider::GetBoundingRectangles

## Description

Retrieves a collection of bounding rectangles for each fully or partially visible line of text in a text range.

## Parameters

### `pRetVal` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray)****

Receives a pointer to one of the following.

* An array of bounding rectangles
  for each full or partial line of text in a text range.
* An empty array for a degenerate range.
* An empty array for a text range that has screen coordinates placing it completely
  off-screen, scrolled out of view, or obscured by an overlapping window.

This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)