# IFsiDirectoryItem::get_Item

## Description

Retrieves the specified directory or file item from file system image.

## Parameters

### `path` [in]

String that contains the path to the item to retrieve.

### `item` [out]

An [IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem) interface of the requested directory or file item.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PATH** | Path '%1!s!' is badly formed or contains invalid characters.<br><br>Value: 0xC0AAB110 |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_ITEM_NOT_FOUND** | Cannot find item *%1!ls!* in FileSystemImage hierarchy.<br><br>Value: 0xC0AAB118 |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory.<br><br>Value: 0x8007000E |

## Remarks

To determine whether the item is a file item or directory item, call the [IFsiItem::QueryInterface](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem) method passing __uuidof(IFsiDirectoryItem) as the interface identifier. If the call succeeds, the item is a directory item; otherwise, the item is a file item.

To enumerate all children, call the [IFsiDirectoryItem::get__NewEnum](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-get__newenum) method.

## See also

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

IFsiFileItem