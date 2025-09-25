# IExplorerBrowser::SetEmptyText

## Description

Sets the default empty text.

## Parameters

### `pszEmptyText` [in]

Type: **LPCWSTR**

A pointer to a constant, null-terminated, Unicode string that contains the empty text.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 The text set is displayed when the Explorer browser view is empty.

This method applies the empty text string to the current view and sets the default empty text string that is used when navigating to another location.

 If this method is not called, the empty text will default to the text provided by the folder that has been navigated to.