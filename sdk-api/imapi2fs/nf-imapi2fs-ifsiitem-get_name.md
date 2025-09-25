# IFsiItem::get_Name

## Description

Retrieves the name of the directory or file item in the file system image.

## Parameters

### `pVal` [out]

String that contains the name of the file or directory item in the file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

To get the full path to the item, call the [IFsiItem::get_FullPath](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-get_fullpath) method.

## See also

[IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem)

[IFsiItem::get_FullPath](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-get_fullpath)