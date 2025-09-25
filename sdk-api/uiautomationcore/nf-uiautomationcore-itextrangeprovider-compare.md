# ITextRangeProvider::Compare

## Description

Retrieves a value that specifies whether this text range has the same endpoints as another text range.

## Parameters

### `range` [in]

Type: **[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)***

The text range to compare with this one.

### `pRetVal` [out, retval]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Receives **TRUE** if the text ranges have the same endpoints, or **FALSE** if they do not.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method compares the endpoints of the two text ranges, not the text in the ranges. The ranges are identical if they share the same endpoints. If two text ranges have different endpoints, they are not identical even if the text in both ranges is exactly the same.

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)