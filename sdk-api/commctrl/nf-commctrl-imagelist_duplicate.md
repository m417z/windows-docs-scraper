# ImageList_Duplicate function

## Description

Creates a duplicate of an existing image list.

## Parameters

### `himl`

Type: **HIMAGELIST**

A handle to the image list to be duplicated. All information contained in the original image list for normal images is copied to the new image list. Overlay images are not copied.

## Return value

Type: **HIMAGELIST**

Returns the handle to the new duplicate image list if successful, or **NULL** otherwise.