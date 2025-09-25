# IFileSystemImage::put_FileSystemsToCreate

## Description

Sets the file systems to create when generating the result stream.

## Parameters

### `newVal` [in]

One or more file systems to create when generating the result stream. For possible values, see the [FsiFileSystems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsifilesystems) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_TOO_MANY_DIRS** | This file system image has too many directories for the *%1!ls!* file system.<br><br>Value: 0xC0AAB130 |
| **IMAPI_E_FILE_SYSTEM_CHANGE_NOT_ALLOWED** | You cannot change the file system specified for creation, because the file system in the imported session and the one in the new session do not match.<br><br>Value: 0xC0AAB163L |
| **IMAPI_E_ISO9660_LEVELS** | ISO9660 is limited to 8 levels of directories.<br><br>Value: 0xC0AAB131 |
| **IMAPI_E_INCOMPATIBLE_PREVIOUS_SESSION** | You cannot change the file system specified for creation, because the file system from the imported session and the file system in the current session do not match.<br><br>Value: 0xC0AAB133 |
| **IMAPI_S_IMAGE_FEATURE_NOT_SUPPORTED** | This feature is not supported for the current file system revision. The image will be created without this feature.<br><br>Value: 0x00AAB15FL |

## Remarks

This method returns **IMAPI_E_INCOMPATIBLE_PREVIOUS_SESSION** if the previous session was imported using [IFileSystemImage::ImportFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importfilesystem) or [IFileSystemImage::ImportSpecificFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importspecificfilesystem) and the layout of that session is incompatible with the layout used by IMAPI for the file systems identified by the specified *newVal* in **IFileSystemImage::put_FileSystemToCreate**.

You can change the file system only when the result stream is not active.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::CreateResultImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-createresultimage)

[IFileSystemImage::get_FileSystemsToCreate](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_filesystemstocreate)