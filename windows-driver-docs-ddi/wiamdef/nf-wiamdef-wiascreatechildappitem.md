# wiasCreateChildAppItem function

## Description

The **wiasCreateChildAppItem** function creates a new application item and inserts it as a child of the specified parent item. Note that this item will not have any properties in its property sets until the driver or application actually fills them in.

## Parameters

### `pParentWiasContext` [in]

Pointer to the item context to which the child will be added.

### `lFlags`

Is reserved for system use.

### `bstrItemName` [in]

Specifies a string that contains the item name without path information.

### `bstrFullItemName` [in]

Specifies a string that contains the item name including path information.

### `ppWiasChildContext` [out]

Pointer to a memory location that receives the address of the newly created child item's context.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## See also

[wiasCreateDrvItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatedrvitem)