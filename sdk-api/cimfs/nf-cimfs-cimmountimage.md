## Description

Mounts the named image from the location specified by cimPath as a volume with the volume GUID specified by volumeId.

## Parameters

### `imageContainingPath`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The directory that will contain the image created. The caller must have FILE_ADD_FILE and FILE_LIST_DIRECTORY access rights.

### `imageName`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Provides the name of an existing image within the same imageContainingPath that will be mounted.

### `mountImageFlags`

Type: **[CIM_MOUNT_IMAGE_FLAGS](https://learn.microsoft.com/windows/win32/api/cimfs/ne-cimfs-cim_mount_image_flags)**

### `volumeId`

Type: **GUID\***
Provides a GUID to be used as the volume GUID of the mounted volume.

## Return value

**[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
E_INVALIDARG – The caller specified an invalid flag.
HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND) – the image path is not found.
HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) – imageName is not found at the path specified.
E_ACCESSEDDENIED – The caller does not have access the image or does not have access to mount a volume.
HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS) – A volume is already mounted with the volume GUID specified.

## Remarks

The mounted volume can be accessed at its volume GUID path as defined by the system. This path is in the form \\?\Volume{GUID}. Mounting the volume allows the image created to be verified using the Windows file system APIs such as CreateFile, FindFirstFile/FindNextFile, GetFileAttributesEx and others.

The image cannot be overwritten while it is mounted.

## See also