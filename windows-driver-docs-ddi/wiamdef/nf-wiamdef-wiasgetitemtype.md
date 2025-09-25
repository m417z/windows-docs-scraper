# wiasGetItemType function

## Description

The **wiasGetItemType** function indicates the item type.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `plType`

Pointer to a memory location that receives a value indicating the type of the item.

For more information, see [WIA Item Type Flags](https://learn.microsoft.com/windows/win32/wia/-wia-wia-item-type-flags).

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).