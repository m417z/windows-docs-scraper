## Description

The **IWiaDrvItem::RemoveItemFromFolder** method removes an item from a parent folder.

## Parameters

### `__MIDL__IWiaDrvItem0006`

*lReason* [in]

Specifies the reason for the removal of the item from the folder. This parameter can be set to one of the following values:

| Value | Description |
|--|--|
| WiaItemTypeDeleted | The item is marked as deleted. |
| WiaItemTypeDisconnected | The item is a disconnected device. |

## Return value

If the method succeeds, it returns **S_OK**. If the item to be removed is a folder and the folder is not empty, the method returns **E_INVALIDARG**. If *lReason* contains an invalid reason, the method returns **E_INVALIDARG**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

After the item has been removed from the folder, it can no longer be used for device access.

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[IWiaDrvItem::AddItemToFolder](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-additemtofolder)