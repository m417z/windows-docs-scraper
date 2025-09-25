## Description

Creates a handle representing a new image at the location specified, optionally based on an existing image at that location.

## Parameters

### `imageContainingPath`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The directory that will contain the image created. The caller must have FILE_ADD_FILE and FILE_LIST_DIRECTORY access rights. The directory will be opened without sharing write access so image creation within a given image directory must be serialized by the caller.

### `existingImageName`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Optionally provides the name of an existing image within the same imageContainingPath that will form the base of the new image. If provided, the existing image can be extended or forked when this image is later committed. This parameter must be NULL and the newImageName parameter must be provided to create an image from scratch.

### `newImageName`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Optionally provides the name of a new image to be created within the imageContainingPath. If this parameter is not provided the existingImageName parameter must be provided and the new image will overwrite the existing image. When both existingImageName and newImageName are provided the image will be overwritten if they are the same name or will be forked if they are different names.
When an image is forked the existing image is preserved such that both the existing and the new image can be mounted independently.

### `cimImageHandle`

Receives an opaque handle that represents a writer for the image. This handle may be passed in subsequent routines to modify the image.

## Return value

**[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
E_ACCESSDENIED - the caller does not have permissions to the specified image containing path.
E_INVALIDARG –The caller failed to specify existingImageName and newImageName.
HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND) – the image containing path does not exist.
HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) - existingImageName is specified and an image by that name is not found in the containing path.
HRESULT_FROM_WIN32(ERROR_FILE_EXISTS) – the newImageName differs from the existingImageName and the newImageName already exists at the path specified.
HRESULT_FROM_WIN32(ERROR_SHARING_VIOLATION) – A sharing violation occurred on the image containing path. Only one image handle may be created per image containing path.

## Remarks

## See also