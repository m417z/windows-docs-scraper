## Description

The **IWiaDrvItem::GetDeviceSpecContext** method gets a device-specific context.

## Parameters

### `__MIDL__IWiaDrvItem0001`

*ppSpecContext* [out, optional]

Points to a memory location that will receive the address of a device-specific context.

## Return value

If the method succeeds, it stores a pointer to the device-specific context in *ppSpecContext* and returns **S_OK**. If the method fails because the parameter *ppSpecContext* specifies an invalid pointer, the method returns **E_INVALIDARG**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

Minidrivers typically use this method to obtain a pointer to a device-specific context associated with an **IWiaDrvItem** item. The device-specific context is associated with the item when the item is created using the driver services library function [wiasCreateDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatedrvitem).

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[wiasCreateDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatedrvitem)