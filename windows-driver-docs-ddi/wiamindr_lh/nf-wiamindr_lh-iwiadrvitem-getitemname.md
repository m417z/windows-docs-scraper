## Description

The **IWiaDrvItem::GetItemName** method gets the current **IWiaDrvItem** item name, not including path information.

## Parameters

### `__MIDL__IWiaDrvItem0003`

*pbstrItemName* [out, optional]

Points to a memory location that will receive the address of the string containing the item name.

## Return value

If the method succeeds, it stores a pointer to the item's name (path information is not included) in *pbstrItemName* and returns **S_OK**. If the method fails to allocate the string due to insufficient memory, it returns **E_OUTOFMEMORY**. If the parameter *pbstrItemName* is invalid, the method returns **E_INVALIDARG**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

If there is enough memory available, the method allocates a string containing the current item's name, excluding path information. The method returns a pointer to the string in *pbstrItemName*. The minidriver must deallocate the memory used by the string by calling the [**SysFreeString**](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring) function.

## See also

[IWiaDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem)

[IWiaDrvItem::GetFullItemName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiadrvitem-getfullitemname)