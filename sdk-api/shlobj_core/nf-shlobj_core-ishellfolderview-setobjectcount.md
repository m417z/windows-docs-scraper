# IShellFolderView::SetObjectCount

## Description

[**SetObjectCount** is no longer available for use as of Windows Vista.]

Sets the number of items in the ListView control that the view contains.

## Parameters

### `uCount`

Type: **UINT**

The number of items to set the ListView control to.

### `dwFlags`

Type: **UINT**

Flags that control the behavior of the ListView control when the number of items is set. Includes the following:

#### SFVSOC_INVALIDATE_ALL (0x00000001)

The ListView control will not repaint unless affected items are currently in view. This is the default value.

#### SFVSOC_NOSCROLL (LVSICF_NOSCROLL)

The ListView control will not change the scroll position when the item count changes.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. Starting with Windows Vista, calls to **SetObjectCount** always return E_NOTIMPL.

## Remarks

This method sends LVM_SETITEMCOUNT to the ListView control that the view contains, with WPARAM equal to *uCount* and LPARAM equal to *dwFlags*.