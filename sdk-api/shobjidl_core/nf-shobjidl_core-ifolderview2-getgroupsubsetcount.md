# IFolderView2::GetGroupSubsetCount

## Description

Gets the count of visible rows displayed for a group's subset.

## Parameters

### `pcVisibleRows` [out]

Type: **UINT***

The number of rows currently visible.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If group subsetting is disabled the number of rows is zero.