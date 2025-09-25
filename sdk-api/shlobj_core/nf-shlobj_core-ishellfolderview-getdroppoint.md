# IShellFolderView::GetDropPoint

## Description

[This method is available through Windows Vista. It might be altered or unavailable in subsequent versions of Windows.]

Gets the point at which the current drag-and-drop operation was terminated.

## Parameters

### `ppt` [out]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a structure that, when this method returns successfully, receives the coordinates at which the current drag-and-drop operation was terminated.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, **S_FALSE** if the view does not have a drop point, or an error value otherwise.