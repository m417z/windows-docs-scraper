# IImageList::GetIcon

## Description

Creates an icon from an image and a mask in an image list.

## Parameters

### `i` [in]

Type: **int**

A value of type **int** that contains the index of the image.

### `flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of flags that specify the drawing style. For a list of values, see [IImageList::Draw](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-draw).

### `picon` [out]

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to an **int** that contains the handle to the icon if successful, or **NULL** if otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The calling application must destroy the icon returned from this method using [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon).

To use **IImageList::GetIcon**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).