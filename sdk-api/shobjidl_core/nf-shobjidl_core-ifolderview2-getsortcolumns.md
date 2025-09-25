# IFolderView2::GetSortColumns

## Description

Gets the sort columns currently applied to the view.

## Parameters

### `rgSortColumns` [out]

Type: **const [SORTCOLUMN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-sortcolumn)***

A pointer to a [SORTCOLUMN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-sortcolumn) structure. The size of this structure is determined by *cColumns*.

### `cColumns` [in]

Type: **int**

The count of columns to sort by.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.