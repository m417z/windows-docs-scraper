## Description

The **IWiaDrvItem::GetNextSiblingItem** method gets the next sibling of the current item in an **IWiaDrvItem** folder.

## Parameters

### `__MIDL__IWiaDrvItem0014`

*ppISiblingItem* [out, optional]

Points to a memory location that will receive the address of the **IWiaDrvItem** object representing the next sibling item in a folder.

## Return value

If the method succeeds, it stores a pointer to the next sibling item in *ppISiblingItem* and returns **S_OK**. If there are no more items in the folder, the method returns **S_FALSE**. If the method fails, it returns a standard COM error code.

## Remarks

Minidrivers obtain a pointer to the first child item in a folder by calling [IWiaDrvItem::GetFirstChildItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getfirstchilditem). Minidrivers can then obtain the sibling items of this child item in the folder by making successive calls to **IWiaDrvItem::GetNextSiblingItem**.

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[IWiaDrvItem::GetFirstChildItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getfirstchilditem)

[IWiaDrvItem::GetParentItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getparentitem)