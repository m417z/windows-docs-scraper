# IHeaderCtrl::GetColumnText

## Description

Retrieves text from a specified column.

## Parameters

### `nCol` [in]

A zero-based index that identifies the column from which the text is to be retrieved.

### `pText` [out]

A pointer to the address of the text to be retrieved. This pointer must not be **NULL**. The user must call
**CoTaskMemFree** on the returned text.

## Return value

This method can return one of these values.

## Remarks

**GetColumnText** allocates the string for the result and stores its pointer at the location specified by pText. The caller must free the memory using
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[IHeaderCtrl](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iheaderctrl)