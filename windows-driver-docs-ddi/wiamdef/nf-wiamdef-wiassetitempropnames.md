## Description

The **wiasSetItemPropNames** function writes property names to item properties.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `cItemProps`

Specifies the number of property names to write.

### `ppId` [in, out]

Pointer to the first element of a caller-allocated array of property identifiers (PROPIDs).

### `ppszNames` [in, out]

Pointer to the first element of a caller-allocated array of property names to write.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## Remarks

Minidrivers typically use this function when initializing item properties. The order of property identifiers in *ppId* must match the order of property names in *ppSzNames*.

## See also

[wiasSetItemPropAttribs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetitempropattribs)