## Description

The **IWiaDrvItem::FindItemByName** method locates an item in a driver item tree by the item's full name.

## Parameters

### `__MIDL__IWiaDrvItem0007`

*bstrFullItemName* [in]

Specifies the full name of the item to find.

### `__MIDL__IWiaDrvItem0008`

*lFlags* [in]

Reserved. Set to zero.

### `__MIDL__IWiaDrvItem0009`

*ppItem* [out, optional]

Points to a memory location that will receive the address of the found **IWiaDrvItem** item.

## Return value

If the method succeeds, it stores a pointer to the found item in *ppItem* and returns **S_OK**. If the method fails, it places **NULL** in *ppItem* and returns **S_FALSE**. If this method does not find the required item, it returns S_FALSE. If an error occurred during the search, a standard COM error code will be returned.

## Remarks

Minidrivers call this method to find an item in a driver item tree when the item's full name is known. The item's full name is obtained in the method [IWiaDrvItem::GetFullItemName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getfullitemname).

This method starts the search for the specified item at the root item in the driver item tree.

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[IWiaDrvItem::FindChildItemByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-findchilditembyname)

[IWiaDrvItem::GetFullItemName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getfullitemname)