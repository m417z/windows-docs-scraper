# KsAllocateObjectCreateItem function

## Description

The **KsAllocateObjectCreateItem** function allocates a slot for the specified create item, optionally allocating space for and copying the create item data as well. This function assumes that the caller is serializing multiple changes to the create entry list.

## Parameters

### `Header` [in]

Points to the device header on which to attach the create item.

### `CreateItem` [in]

Contains the create item to attach.

### `AllocateEntry` [in]

Indicates whether the create item pointer passed should be attached directly to the header, or if a copy of it should be made instead.

### `ItemFreeCallback` [in, optional]

Optionally contains a pointer to a minidriver-defined [KStrItemFreeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksitemfreecallback) function to be called when the create entry is being destroyed upon freeing the device header. This is only valid when *AllocateEntry* is **TRUE**.

## Return value

Returns STATUS_SUCCESS if a new item was allocated and attached. Otherwise, it returns STATUS_INSUFFICIENT_RESOURCES.

## See also

[KStrItemFreeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksitemfreecallback)