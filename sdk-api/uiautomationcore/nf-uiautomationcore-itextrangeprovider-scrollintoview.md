# ITextRangeProvider::ScrollIntoView

## Description

Causes the text control to scroll vertically until the text range is visible in the viewport.

## Parameters

### `alignToTop` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

TRUE if the text control should be scrolled so the text range is flush with the top of the viewport;
FALSE if it should be flush with the bottom of the viewport.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**ITextRangeProvider::ScrollIntoView** respects both hidden and visible text.

If the text range is hidden, the text control will scroll only if the hidden text has an anchor in the viewport.

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)