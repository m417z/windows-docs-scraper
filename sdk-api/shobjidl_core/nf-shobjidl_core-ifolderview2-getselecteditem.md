# IFolderView2::GetSelectedItem

## Description

Locates the currently selected item at or after a given index.

## Parameters

### `iStart` [in]

Type: **int**

The index position from which to start searching for the currently selected item.

### `piItem` [out]

Type: **int***

A pointer to a value that receives the index of the item in the view.

## Return value

Type: **HRESULT**

Returns S_OK if a selected item was found, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **S_FALSE** | Item not found. Note that this is a success code. The operation was successful in searching the view, it simply did not find a currently selected item after the given index (*iStart*). It is possible that no item was selected, or that the selected item had an index less than *iStart*. |