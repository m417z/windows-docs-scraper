# IMenuPopup::OnSelect

## Description

Handles selection notifications.

## Parameters

### `dwSelectType`

Type: **DWORD**

This parameter can be any of the following values.

#### MPOS_EXECUTE

Execute the selected menu item.

#### MPOS_FULLCANCEL

Cancel the entire menu.

#### MPOS_CANCELLEVEL

Cancel the current cascaded menu.

#### MPOS_SELECTLEFT

Select the item to the left of the current selection.

#### MPOS_SELECTRIGHT

Select the item to the right of the current selection.

#### MPOS_CHILDTRACKING

The child of the current selection receives a tracking selection. In other words, the mouse moves over the child of the current selection.

## Return value

Type: **HRESULT**

Always returns S_OK.