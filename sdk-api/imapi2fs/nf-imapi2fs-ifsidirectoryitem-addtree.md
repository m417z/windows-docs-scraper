# IFsiDirectoryItem::AddTree

## Description

Adds the contents of a directory tree to the file system image.

## Parameters

### `sourceDirectory` [in]

String that contains the relative path of the directory tree to create.

Specify the full path when calling this method from the root directory item.

### `includeBaseDirectory` [in]

Set to VARIANT_TRUE to include the directory in *sourceDirectory* as a subdirectory in the file system image. Otherwise, VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_DIRECTORY_READ_FAILURE** | Failure enumerating files in the directory tree is inaccessible due to permissions.<br><br>Value: 0xC0AAB12BL |
| **IMAPI_E_DATA_STREAM_CREATE_FAILURE** | One or more of the files in the directory tree is inaccessible due to permissions.<br><br>Value: 0xC0AAB12A |
| **IMAPI_E_DATA_STREAM_READ_FAILURE** | Cannot read data from stream supplied for file '%1!ls!'.<br><br>Value: 0xC0AAB129 |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_NOT_IN_FILE_SYSTEM** | *ls!'* is not part of the file system. It must be added to complete this operation.<br><br>Value: 0xC0AAB10B |
| **IMAPI_E_READONLY** | FileSystemImage object is in read only mode.<br><br>Value: 0xC0AAB102 |
| **IMAPI_E_IMAGE_SIZE_LIMIT** | Adding this file or directory would result in a result image having a size larger than the current configured limit.<br><br>Value: 0xC0AAB120 |
| **IMAPI_E_INVALID_PATH** | Path '%1!s!' is badly formed or contains invalid characters.<br><br>Value: 0xC0AAB110 |
| **IMAPI_E_DUP_NAME** | ls!' name already exists.<br><br>Value: 0xC0AAB112 |
| **IMAPI_E_NO_UNIQUE_NAME** | Attempt to add '%1!ls!' failed: cannot create a file-system-specific unique name for the %2!ls! file system.<br><br>Value: 0xC0AAB113 |
| **IMAPI_E_ISO9660_LEVELS** | ISO9660 is limited to 8 levels of directories.<br><br>Value: 0xC0AAB131 |
| **IMAPI_E_TOO_MANY_DIRS** | This file system image has too many directories for the %1!ls! file system.<br><br>Value: 0xC0AAB130 |
| **IMAPI_E_DIR_NOT_FOUND** | The directory '%1!s!' not found in FileSystemImage hierarchy.<br><br>Value: 0xC0AAB11A |

**Note** Values returned by the [GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa) and [FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea) functions may also be returned here.

## Remarks

The parent directory for the new subdirectory must already exist within the file system image.

The subdirectory structure within specified source directory is implicitly mirrored in the file system image.

If file or directory collisions occur, the content of the specified source directory prevails. The file system image is overwritten with the appropriate directories and files from the source directory.

If an exception occurs during processing, the file system image reverts to its previous state.

## See also

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

[IFsiDirectoryItem::Add](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-add)

[IFsiDirectoryItem::AddDirectory](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-adddirectory)

[IFsiDirectoryItem::AddFile](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addfile)

[IFsiDirectoryItem::Remove](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-remove)