# IExplorerBrowser::RemoveAll

## Description

Removes all items from the results folder.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or E_UNEXPECTED if this method is called before a call to [IExplorerBrowser::FillFromObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-fillfromobject).

## Remarks

This method removes all results from the [IResultsFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iresultsfolder) created in method [IExplorerBrowser::FillFromObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-fillfromobject).