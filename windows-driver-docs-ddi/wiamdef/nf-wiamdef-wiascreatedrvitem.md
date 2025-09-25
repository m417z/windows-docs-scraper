# wiasCreateDrvItem function

## Description

The **wiasCreateDrvItem** function creates an [IWiaDrvItem Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem) object.

## Parameters

### `lObjectFlags`

Specifies the object item type, which must be **WiaItemTypeFolder** or **WiaItemTypeFile** (possibly the bitwise OR of these). These flags are described in [WIA Item Type Flags](https://learn.microsoft.com/windows/win32/wia/-wia-wia-item-type-flags).

### `bstrItemName`

Specifies a string that contains the item name without path information.

### `bstrFullItemName`

Specifies a string that contains the item name with path information.

### `pIMiniDrv` [in, out]

Pointer to the [IWiaMiniDrv Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv) of the current minidriver.

### `cbDevSpecContext`

Specifies the size in bytes of the device specific context.

### `ppDevSpecContext` [out]

Pointer to a memory location that receives the address of the device specific context. Set this to **NULL** if the information is not needed.

### `ppIWiaDrvItem` [out]

Pointer to a memory location that receives the address of an [IWiaDrvItem Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem) for the newly created **IWiaDrvItem** object.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

This function creates and initializes an [IWiaDrvItem COM Interface](https://learn.microsoft.com/windows-hardware/drivers/image/iwiadrvitem-com-interface) object with the specified name and attributes. It also creates a context for the **IWiaDrvItem** object. Minidrivers typically use this function to build a tree of device items.

## See also

[wiasCreateChildAppItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatechildappitem)