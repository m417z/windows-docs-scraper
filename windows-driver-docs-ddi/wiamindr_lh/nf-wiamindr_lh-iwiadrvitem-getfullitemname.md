## Description

The **IWiaDrvItem::GetFullItemName** method gets the item's full name, including path information.

## Parameters

### `__MIDL__IWiaDrvItem0002`

*pbstrFullItemName* [out, optional]

Points to a memory location that will receive the address of a string containing the item's full name.

## Return value

If the method succeeds, it stores a pointer to the item's full name, including path information, in *pbstrFullItemName* and returns **S_OK**. If the method fails to allocate the string due to insufficient memory, it returns **E_OUTOFMEMORY**. If the parameter *pbstrFullItemName* is invalid, the method returns **E_INVALIDARG**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

If there is enough memory available, this method allocates a string containing the current item's full name including path information. The method returns a pointer to the string in *pbstrFullItemName*. The minidriver must deallocate the memory used by the string by calling the [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring) function.

The name returned in *pbstrFullItemName* is the name associated with the item when the item was first created by the driver services library function [wiasCreateDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatedrvitem).

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[wiasCreateDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatedrvitem)