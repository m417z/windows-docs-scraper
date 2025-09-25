# IFolderView2::GetVisibleItem

## Description

Gets the next visible item in relation to a given index in the view.

## Parameters

### `iStart` [in]

Type: **int**

The zero-based position at which to start searching for a visible item.

### `fPrevious` [in]

Type: **BOOL**

**TRUE** to find the first visible item before *iStart*. **FALSE** to find the first visible item after *iStart*.

### `piItem` [out]

Type: **int***

When this method returns, contains a pointer to a value that receives the index of the visible item in the view.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Item retrieved. |
| **S_FALSE** | Item not found. Note that this is a success code. |