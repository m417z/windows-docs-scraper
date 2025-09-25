# wiasGetContextFromName function

## Description

The **wiasGetContextFromName** function retrieves the item context for an item name.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `lFlags`

Reserved for system use and should be set to 0.

### `bstrName` [in]

Specifies the name of the context that is being searched for.

### `ppWiasContext` [out]

Pointer to a memory location that receives the address of the WIA item context.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

This function searches for item contexts whose WIA_IPA_FULL_ITEM_NAME property matches *bstrName*. Note that this property is different from WIA_IPA_ITEM_NAME, which does not contain path information.

This function should be used by minidrivers when they need to move from one application item context to another, given the item's name. The names of the application items come from their corresponding driver items, which the minidriver creates and names.

## See also

[wiasGetRootItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetrootitem)