## Description

The **IWiaDrvItem::GetFirstChildItem** method gets the first child item in an **IWiaDrvItem** folder item.

## Parameters

### `__MIDL__IWiaDrvItem0013`

*ppIChildItem* [out, optional]

Points to a memory location that will receive the address of an **IWiaDrvItem** child item.

## Return value

If the method succeeds, it stores a pointer to the first child item in *ppIChildItem* and returns **S_OK**. If a child item cannot be found, the method returns **S_FALSE**. If the item being searched is not a folder, the method returns **E_INVALIDARG**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

Minidrivers typically use this method to retrieve the first child item in a driver item folder. The item being searched must be a folder item.

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[IWiaDrvItem::GetNextSiblingItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getnextsiblingitem)

[IWiaDrvItem::GetParentItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getparentitem)