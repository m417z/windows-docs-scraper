# IFsiItem::get_FullPath

## Description

Retrieves the full path of the file or directory item in the file system image.

## Parameters

### `pVal` [out]

String that contains the absolute path of the file or directory item in the file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem)

[IFsiItem::get_Name](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-get_name)