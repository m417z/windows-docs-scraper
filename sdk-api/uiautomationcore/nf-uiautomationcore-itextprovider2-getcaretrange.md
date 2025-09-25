# ITextProvider2::GetCaretRange

## Description

Provides a zero-length text range at the location of the caret that belongs to the text-based control.

## Parameters

### `isActive` [out]

Type: **BOOL***

**TRUE** if the text-based control that contains the caret has keyboard focus, otherwise **FALSE**.

### `pRetVal` [out, retval]

Type: **[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)****

 A text range that represents the current location of the caret that belongs to the text-based control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the *isActive* parameter is **FALSE**, the caret that belongs to the text-based control might not be at the same location as the system caret.

This method retrieves a text range that a client can use to find the bounding rectangle of the caret that belongs to the text-based control, or to find the text near the caret.

## See also

[ITextProvider2](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider2)