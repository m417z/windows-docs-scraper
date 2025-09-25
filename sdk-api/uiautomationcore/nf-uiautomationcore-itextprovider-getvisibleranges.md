# ITextProvider::GetVisibleRanges

## Description

Retrieves an array of disjoint text ranges from a text-based control where each text range represents a contiguous span of visible text.

## Parameters

### `pRetVal` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives the address of an array of pointers to the
[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider) interfaces of the visible
text ranges or an empty array.
A **NULL** reference is never returned.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the visible text consists of one contiguous span of text, the *pRetVal* array should contain a single text range that represents all of the visible text.

If the visible text consists of multiple, disjoint spans of text, the *pRetVal* array should contain one text range for each visible span, beginning with the first visible span, and ending with the last visible span. Disjoint spans of visible text can occur when the content of a text-based control is partially obscured
by an overlapping window or other object, or when a text-based control with multiple pages or columns
has content that is partially scrolled out of view.

**ITextProvider::GetVisibleRanges** should return a degenerate (empty) text range if no text is visible, if all text is scrolled out of view, or if the text-based control contains no text.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)