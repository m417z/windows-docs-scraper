## Description

The **IWiaDrvItem::GetItemFlags** method gets the item flags of the current **IWiaDrvItem** item.

## Parameters

### `__MIDL__IWiaDrvItem0000`

*plFlags* [out]

Points to a memory location that will receive the item flags.

## Return value

If the method succeeds, it places the item flag values in the location pointed to by *plFlags* and returns S_OK. If the pointer *plFlags* is invalid, the method returns **E_INVALIDARG**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

The method places the current **IWiaDrvItem** item's flag values in the location pointed to by *pIFlags*. The item's flag values were set when the item was created by the driver services library function [wiasCreateDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatedrvitem).

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[wiasCreateDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatedrvitem)