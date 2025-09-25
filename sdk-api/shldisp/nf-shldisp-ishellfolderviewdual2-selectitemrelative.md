# IShellFolderViewDual2::SelectItemRelative

## Description

Selects an item relative to the current item.

## Parameters

### `iRelative` [in]

Type: **int**

The offset of the item to be selected in relation to the current item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The current item is defined as the item in the view with the SVSI_SELECTIONMARK state. If there is no item with SVSI_SELECTIONMARK, the method returns S_FALSE and does nothing.