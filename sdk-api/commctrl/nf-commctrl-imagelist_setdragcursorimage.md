# ImageList_SetDragCursorImage function

## Description

Creates a new drag image by combining the specified image (typically a mouse cursor image) with the current drag image.

## Parameters

### `himlDrag`

Type: **HIMAGELIST**

A handle to the image list that contains the new image to combine with the drag image.

### `iDrag`

Type: **int**

The index of the new image to combine with the drag image.

### `dxHotspot`

Type: **int**

The x-position of the hot spot within the new image.

### `dyHotspot`

Type: **int**

The y-position of the hot spot within the new image.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.