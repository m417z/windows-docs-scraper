# IFolderView2::SetGroupSubsetCount

## Description

Turns on group subsetting and sets the number of visible rows of items in each group.

## Parameters

### `cVisibleRows` [in]

Type: **UINT**

The number of rows to be visible.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *cVisibleRows* is zero, subsetting is turned off.