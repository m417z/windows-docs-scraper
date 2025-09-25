# wiasGetDrvItem function

## Description

The **wiasGetDrvItem** function retrieves a driver item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `ppIWiaDrvItem`

Pointer to a memory location that receives the address of an [IWiaDrvItem Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiadrvitem).

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## See also

[wiasCreateDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatedrvitem)

[wiasGetRootItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetrootitem)