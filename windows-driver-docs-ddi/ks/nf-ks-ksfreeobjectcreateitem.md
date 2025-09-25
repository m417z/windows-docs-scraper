# KsFreeObjectCreateItem function

## Description

Frees the slot for the specified create item.

## Parameters

### `Header` [in]

Points to the device header on which the create item is attached.

### `CreateItem` [in]

Contains the name of the create item to free.

## Return value

Returns STATUS_SUCCESS if the item was freed, else STATUS_OBJECT_NAME_NOT_FOUND.

## Remarks

This function does not assume that the caller is serializing multiple changes to the create entry list.

## See also

[KsFreeObjectCreateItemsByContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectcreateitemsbycontext)