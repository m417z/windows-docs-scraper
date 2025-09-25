# IFsiDirectoryItem::Remove

## Description

Removes the specified item from the file system image.

## Parameters

### `path` [in]

String that contains the relative path of the item to remove.
The path is relative to current directory item.

Specify the full path when calling this method from the root directory item.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PATH** | Path '%1!s!' is badly formed or contains invalid characters.<br><br>Value: 0xC0AAB110 |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory.<br><br>Value: 0x8007000E |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_NOT_IN_FILE_SYSTEM** | *ls!'* is not part of the file system. It must be added to complete this operation.<br><br>Value: 0xC0AAB10B |
| **IMAPI_E_READONLY** | FileSystemImage object is in read only mode.<br><br>Value: 0xC0AAB102 |
| **IMAPI_E_DIR_NOT_EMPTY** | The directory *%1!s!* is not empty.<br><br>Value: 0xC0AAB10A |
| **IMAPI_E_FSI_INTERNAL_ERROR** | Internal error occurred: *%1!ls!*.<br><br>Value: 0xC0AAB100 |

## Remarks

This method is only callable on directory items present in the file system image.

## See also

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

[IFsiDirectoryItem::AddDirectory](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-adddirectory)

[IFsiDirectoryItem::AddFile](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addfile)

[IFsiDirectoryItem::RemoveTree](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-removetree)