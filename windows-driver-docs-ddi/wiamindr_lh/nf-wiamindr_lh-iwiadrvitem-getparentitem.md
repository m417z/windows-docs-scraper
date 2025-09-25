## Description

The **IWiaDrvItem::GetParentItem** gets the parent item of the current item.

## Parameters

### `__MIDL__IWiaDrvItem0012`

*ppIParentItem* [out, optional]

Returns a pointer to the parent item of the current item.

## Return value

If the method succeeds, it stores a pointer to the parent item in *pplParentItem* and returns **S_OK**. If the parent item is the root item, the method returns **S_FALSE**. If the method fails, it returns a standard COM error code.

## Remarks

Minidrivers typically use this method to obtain a pointer to the nonroot parent item of the current item.

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[IWiaDrvItem::GetFirstChildItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getfirstchilditem)

[IWiaDrvItem::GetNextSiblingItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getnextsiblingitem)