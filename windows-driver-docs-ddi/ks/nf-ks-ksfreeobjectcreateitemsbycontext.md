# KsFreeObjectCreateItemsByContext function

## Description

Frees all create items with a specific context.

## Parameters

### `Header` [in]

Points to the device header on which the create items are attached.

### `Context` [in]

Contains the context of the create items to free. All create items with this context value will be freed.

## Return value

Returns STATUS_SUCCESS if the item was freed, else STATUS_OBJECT_NAME_NOT_FOUND.

## Remarks

Instead of freeing create items by name as **KsFreeObjectCreateItems** does, this function will free all create items with a specific context. For example, all create items associated with a filter factory will have the factory as context and can be freed simultaneously with this call instead of one at a time. Note that this function does not assume that the caller is serializing multiple changes to the create entry list.

## See also

[KsFreeObjectCreateItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectcreateitem)