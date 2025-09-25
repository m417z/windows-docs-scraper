# CWiauPropertyList::SendToWia

## Description

The **CWiauPropertyList::SendToWia** method calls the WIA service to define all of the properties currently contained in the property list object.

## Parameters

### `pWiasContext`

Pointer to a WIA item context that previously was passed in a call to the [IWiaMiniDrv::drvInitItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvinititemproperties)> method.

## Return value

On success, the **CWiauPropertyList::SendToWia** method returns S_OK. If the property list contains no properties, the method returns E_FAIL.

## Remarks

The **CWiauPropertyList::SendToWia** method should be called only after all properties have been defined and their values set.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[IWiaMiniDrv::drvInitItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvinititemproperties)