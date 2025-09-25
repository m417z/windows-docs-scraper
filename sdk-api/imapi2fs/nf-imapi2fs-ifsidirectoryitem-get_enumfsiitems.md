# IFsiDirectoryItem::get_EnumFsiItems

## Description

Retrieves a list of child items contained within the directory in the file system image.

## Parameters

### `NewEnum` [out]

An [IEnumFsiItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ienumfsiitems) interface that contains a collection of the child directory and file items contained within the directory.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory.<br><br>Value: 0x8007000E |

## Remarks

This property returns the same results as the [IFsiDirectoryItem::get__NewEnum](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-get__newenum) property and is meant for use by C/C++ applications.

## See also

[IEnumFsiItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ienumfsiitems)

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

[IFsiDirectoryItem::get__NewEnum](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-get__newenum)