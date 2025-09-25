# wiasGetRootItem function

## Description

The **wiasGetRootItem** function retrieves the root item context of a specified WIA item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `ppWiasContext` [out]

Pointer to a memory location that receives the address of the WIA item's root item context.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## See also

[wiasGetDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetdrvitem)