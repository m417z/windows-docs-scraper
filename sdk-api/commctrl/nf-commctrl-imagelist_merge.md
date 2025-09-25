# ImageList_Merge function

## Description

Creates a new image by combining two existing images. The function also creates a new image list in which to store the image.

## Parameters

### `himl1`

Type: **HIMAGELIST**

A handle to the first image list.

### `i1`

Type: **int**

The index of the first existing image.

### `himl2`

Type: **HIMAGELIST**

A handle to the second image list.

### `i2`

Type: **int**

The index of the second existing image.

### `dx`

Type: **int**

The x-offset of the second image relative to the first image.

### `dy`

Type: **int**

The y-offset of the second image relative to the first image.

## Return value

Type: **HIMAGELIST**

Returns the handle to the new image list if successful, or **NULL** otherwise.

## Remarks

The new image consists of the second existing image drawn transparently over the first. The mask for the new image is the result of performing a logical OR operation on the masks of the two existing images.