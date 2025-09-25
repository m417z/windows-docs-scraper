# IFsiDirectoryItem::RemoveTree

## Description

Remove the specified directory tree from the file system image.

## Parameters

### `path` [in]

String that contains the name of directory to remove.
The path is relative to current directory item.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *path* parameter is not a valid pointer. |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_INVALID_PATH** | Path '%1!s!' is badly formed or contains invalid characters.<br><br>Value: 0xC0AAB110 |
| **IMAPI_E_NOT_IN_FILE_SYSTEM** | *ls!'* is not part of the file system. It must be added to complete this operation.<br><br>Value: 0xC0AAB10B |
| **IMAPI_E_READONLY** | FileSystemImage object is in read only mode.<br><br>Value: 0xC0AAB102 |
| **IMAPI_E_DIR_NOT_FOUND** | The specified directory does not exist. |
| **IMAPI_E_DIR_NOT_EMPTY** | The directory *%1!s!* is not empty.<br><br>Value: 0xC0AAB10A |
| **IMAPI_E_FSI_INTERNAL_ERROR** | Internal error occurred: *%1!ls!*.<br><br>Value: 0xC0AAB100 |
| **IMAPI_E_NOT_DIR** | Specified path *%1!ls!* does not identify a directory.<br><br>Value: 0xC0AAB109 |

## Remarks

The directory item must be present in the file system image.

You can delete the entire file-system image by calling this method for the root directory item and setting the path to a single path delimiter (\\).

## See also

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

[IFsiDirectoryItem::AddDirectory](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-adddirectory)

[IFsiDirectoryItem::AddFile](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addfile)

[IFsiDirectoryItem::AddTree](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addtree)

[IFsiDirectoryItem::Remove](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-remove)