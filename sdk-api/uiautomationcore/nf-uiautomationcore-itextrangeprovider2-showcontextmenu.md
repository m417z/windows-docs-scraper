# ITextRangeProvider2::ShowContextMenu

## Description

Programmatically invokes a context menu on the target element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method should return an error code if the context menu could not be invoked.

**ShowContextMenu** should always show the context menu at the beginning end point of the range. This should be equivalent to what would happen if the user pressed the context menu key or SHIFT + F10 with the insertion point at the beginning of the range.

If showing the context menu would typically result in the insertion point moving to a given location, then it should do so for programmatically invoking **ShowContextMenu** for Microsoft UI Automation support also.

## See also

[ITextRangeProvider2](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider2)