# IImageList::ReplaceIcon

## Description

Replaces an image with an icon or cursor.

## Parameters

### `i` [in]

Type: **int**

A value of type **int** that contains the index of the image to replace. If i is -1, the function adds the image to the end of the list.

### `hicon` [in]

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the icon or cursor that contains the bitmap and mask for the new image.

### `pi` [out]

Type: **int***

A pointer to an **int** that will contain the index of the image on return if successful, or -1 otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Because the system does not save *hicon*, you can destroy it after the function returns if the icon or cursor was created by [CreateIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createicon). You do not need to destroy *hicon* if it was loaded by the [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona) function; the system automatically frees an icon resource when it is no longer needed.

To use **IImageList::ReplaceIcon**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).