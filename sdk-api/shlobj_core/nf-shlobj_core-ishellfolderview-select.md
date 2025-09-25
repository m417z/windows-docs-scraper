# IShellFolderView::Select

## Description

[**IShellFolderView::Select** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Selects and unselects items in the view.

## Parameters

### `dwFlags`

Type: **UINT**

Determines which items in the view are selected, if any. One of the following values.

#### SFVS_SELECT_NONE (0x0)

Unselects all of the items in the view.

#### SFVS_SELECT_ALLITEMS (0x1)

Selects all of the items in the view.

#### SFVS_SELECT_INVERT (0x2)

Selects all unselected items and unselects all selected items.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.