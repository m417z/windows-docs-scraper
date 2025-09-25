# IShellFolderView::SetRedraw

## Description

[This method is available through Windows Vista. It might be altered or unavailable in subsequent versions of Windows.]

Allows a view to be redrawn or prevents it from being redrawn.

## Parameters

### `bRedraw`

Type: **BOOL**

**TRUE** if the content can be redrawn after a change; **FALSE** if the content cannot be redrawn after a change.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method sends the [WM_SETREDRAW](https://learn.microsoft.com/windows/desktop/gdi/wm-setredraw) message to the ListView object that the view contains.