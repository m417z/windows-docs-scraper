# IUIAutomationTextRange::GetBoundingRectangles

## Description

Retrieves a collection of bounding rectangles for each fully or partially visible line of text in a text range.

## Parameters

### `boundingRects` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives a pointer to an array of bounding rectangles for each fully or partially visible line of text in a text range. An empty array is returned for a degenerate (empty) text range or for a text range that is completely off-screen, scrolled out of view, or obscured by an overlapping window.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For information about how the bounding rectangles are stored in the SAFEARRAY, see [Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays).

## See also

**Conceptual**

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

**Reference**

[SafeArrayToRectNativeArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-safearraytorectnativearray)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)