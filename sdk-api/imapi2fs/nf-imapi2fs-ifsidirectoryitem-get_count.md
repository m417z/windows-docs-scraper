# IFsiDirectoryItem::get_Count

## Description

Number of child items in the enumeration.

## Parameters

### `Count` [out]

Number of directory and file items within the directory in the file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

[IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem)