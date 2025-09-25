# IFsiDirectoryItem::AddDirectory

## Description

Adds a directory to the file system image.

## Parameters

### `path` [in]

String that contains the relative path of directory to create.

Specify the full path when calling this method from the root directory item.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PATH** | Path '%1!s!' is badly formed or contains invalid characters.<br><br>Value: 0xC0AAB110 |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_NOT_IN_FILE_SYSTEM** | *ls!'* is not part of the file system. It must be added to complete this operation.<br><br>Value: 0xC0AAB10B |
| **IMAPI_E_READONLY** | FileSystemImage object is in read only mode.<br><br>Value: 0xC0AAB102 |

## Remarks

The parent directory for the new subdirectory must already exist within the file system image.

## See also

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

[IFsiDirectoryItem::Add](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-add)

[IFsiDirectoryItem::AddFile](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addfile)

[IFsiDirectoryItem::AddTree](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addtree)

[IFsiDirectoryItem::Remove](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-remove)