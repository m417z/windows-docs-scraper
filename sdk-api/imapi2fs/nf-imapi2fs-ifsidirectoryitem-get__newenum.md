# IFsiDirectoryItem::get__NewEnum

## Description

Retrieves a list of child items contained within the directory in the file system image.

## Parameters

### `NewEnum` [out]

An **IEnumVariant** interface that you use to enumerate the child items contained within the directory. The items of the enumeration are variants whose type is **VT_BSTR**. Use the **bstrVal** member to retrieve the path to the child item.

## Return value

S_OK is returned when the number of requested elements (*celt*) are returned successfully or the number of returned items (*pceltFetched*) is less than the number of requested elements. The *celt* and *pceltFetched* parameters are defined by **IEnumVariant**.

Other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory.<br><br>Value: 0x8007000E |

## Remarks

The enumeration is a snapshot of the children contained in the directory at the time of the call and will not reflect children that are added and removed.

To retrieve a single item, see the [IFsiDirectoryItem::get_Item](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-get_item) property.

## See also

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)

[IFsiDirectoryItem::get_EnumFsiItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-get_enumfsiitems)