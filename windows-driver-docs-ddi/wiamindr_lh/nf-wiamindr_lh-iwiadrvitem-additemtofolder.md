## Description

The *AddItemToFolder* method adds an **IWiaDrvItem** item to a folder in a driver item tree.

## Parameters

### `__MIDL__IWiaDrvItem0004`

*pIParent* [in, optional]

Points to the IWiaDrvItem parent folder item.

## Return value

If the method succeeds, it returns **S_OK**. If the method fails because an invalid *pIParent* parameter is passed, it returns **E_INVALIDARG**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

Minidrivers typically use the *AddItemToFolder* method to add an item to a parent folder item in a driver item tree. The parent folder item is pointed to by the parameter *pIParent*. The item pointed to by *pIParent* must be a folder.

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[RemoveItemFromFolder](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-removeitemfromfolder)