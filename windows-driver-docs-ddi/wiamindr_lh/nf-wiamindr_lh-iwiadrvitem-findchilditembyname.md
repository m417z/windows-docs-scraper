## Description

The **IWiaDrvItem::FindChildItemByName** method searches the driver item tree for a specific child item.

## Parameters

### `__MIDL__IWiaDrvItem0010`

*bstrChildItemName* [in]

Specifies a string containing the name with path information of the child item to find.

### `__MIDL__IWiaDrvItem0011`

*ppIChildItem* [out, optional]

Points to a memory location that will receive the address of the found **IWiaDrvItem** child item.

## Return value

If the method succeeds, it stores a pointer to the found child item in *ppIChildItem* and returns **S_OK**. If the method fails to find the child item, it returns **S_FALSE**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

Minidrivers typically use this method to search a driver item tree for a specific child item when the child item's name is known. The child item's full name is obtained in the method [IWiaDrvItem::GetFullItemName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getfullitemname).

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[IWiaDrvItem::FindItemByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-finditembyname)

[IWiaDrvItem::GetFullItemName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getfullitemname)