# ImageList_ReplaceIcon function

## Description

Replaces an image with an icon or cursor.

## Parameters

### `himl` [in]

Type: **HIMAGELIST**

A handle to the image list.

### `i` [in]

Type: **int**

The index of the image to replace. If
*i* is -1, the function appends the image to the end of the list.

### `hicon` [in]

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle to the icon or cursor that contains the bitmap and mask for the new image.

## Return value

Type: **int**

Returns the index of the image if successful, or -1 otherwise.

## Remarks

Because the system does not save
*hicon*, you can destroy it after the function returns if the icon or cursor was created by the [CreateIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createicon) function. You do not need to destroy *hicon* if it was loaded by the [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona) function; the system automatically frees an icon resource when it is no longer needed.