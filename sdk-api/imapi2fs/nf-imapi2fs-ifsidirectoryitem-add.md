# IFsiDirectoryItem::Add

## Description

Adds a file or directory described by the [IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem) object to the file system image.

## Parameters

### `item` [in]

An [IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem) interface of the [IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem) or [IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem) to add to the file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_INVALID_PATH** | Path '%1!s!' is badly formed or contains invalid characters.<br><br>Value: 0xC0AAB110 |
| **IMAPI_E_DATA_STREAM_READ_FAILURE** | Cannot read data from stream supplied for file '%1!ls!'.<br><br>Value: 0xC0AAB129 |
| **IMAPI_E_DUP_NAME** | ls!' name already exists.<br><br>Value: 0xC0AAB112 |
| **IMAPI_E_NO_UNIQUE_NAME** | Attempt to add '%1!ls!' failed: cannot create a file-system-specific unique name for the %2!ls! file system.<br><br>Value: 0xC0AAB113 |
| **IMAPI_E_IMAGE_SIZE_LIMIT** | Adding '%1!ls!' would result in a result image having a size larger than the current configured limit.<br><br>Value: 0xC0AAB120 |
| **IMAPI_E_ISO9660_LEVELS** | ISO9660 is limited to 8 levels of directories.<br><br>Value: 0xC0AAB131 |
| **IMAPI_E_TOO_MANY_DIRS** | This file system image has too many directories for the %1!ls! file system.<br><br>Value: 0xC0AAB130 |
| **IMAPI_E_DIR_NOT_FOUND** | The directory '%1!s!' not found in FileSystemImage hierarchy.<br><br>Value: 0xC0AAB11A |
| **IMAPI_E_NOT_IN_FILE_SYSTEM** | This file or directory is not part of the file system. It must be added to complete this operation.<br><br>Value: 0xC0AAB10B |
| **IMAPI_E_READONLY** | FileSystemImage object is in read only mode.<br><br>Value: 0xC0AAB102 |
| **IMAPI_E_IMAGE_SIZE_LIMIT** | Adding this file or directory would result in a result image having a size larger than the current configured limit.<br><br>Value: 0xC0AAB120 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

**Note** Values returned by the IUnknown::QueryInterface method may also be returned here.

## Remarks

To create a directory item or file item, call the [IFileSystemImage::CreateDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-createdirectoryitem) or [IFileSystemImage::CreateFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-createfileitem) method, respectively.

Once an item is added to the file system image, the [IFsiFileItem::get_Data](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsifileitem-get_data) property becomes read-only.

## See also

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

[IFsiDirectoryItem::AddDirectory](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-adddirectory)

[IFsiDirectoryItem::AddFile](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addfile)

[IFsiDirectoryItem::Remove](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-remove)

[IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem)