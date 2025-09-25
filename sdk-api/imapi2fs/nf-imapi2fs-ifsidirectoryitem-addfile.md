# IFsiDirectoryItem::AddFile

## Description

Adds a file to the file system image.

## Parameters

### `path` [in]

String that contains the relative path of the directory to contain the new file.

Specify the full path when calling this method from the root directory item.

### `fileData` [in]

An **IStream** interface of the file (data stream) to write to the media.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PATH** | Path '%1!s!' is badly formed or contains invalid characters.<br><br>Value: 0xC0AAB110 |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_NOT_IN_FILE_SYSTEM** | *ls!'* is not part of the file system. It must be added to complete this operation.<br><br>Value: 0xC0AAB10B |
| **IMAPI_E_READONLY** | FileSystemImage object is in read only mode.<br><br>Value: 0xC0AAB102 |

## Remarks

The directory that will contain the new file must already exist within the file system image.

## See also

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

[IFsiDirectoryItem::Add](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-add)

[IFsiDirectoryItem::AddDirectory](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-adddirectory)

[IFsiDirectoryItem::Remove](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-remove)