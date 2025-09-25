# KsRemoveItemFromObjectBag function

## Description

The **KsRemoveItemFromObjectBag** function removes an item from an object bag.

## Parameters

### `ObjectBag` [in]

This parameter specifies the KSOBJECT_BAG (equivalent to type PVOID) from which to remove *Item*.

### `Item` [in]

A pointer to the item to remove from the requested object bag. Note that *Item* is removed from the requested object bag only. It is not removed from any other object bags that it may be in.

### `Free` [in]

This parameter specifies whether *Item* should be freed once it has been removed from the specified object bag. Only set *Free* to **TRUE** if *Item* is not contained in any other object bag.

## Return value

Returns the number of references on *Item*. A return value of zero indicates that *Item* was not in *ObjectBag* at call-time.

A return value of one indicates that *Item* was successfully removed from *ObjectBag* and that it was not in any other object bag. If a free was requested in this case, AVStream frees *Item* using either **ExFreePool** or the Free method specified at **KsAddItemToObjectBag** call-time.

A return value above one indicates that the item is present in another object bag and that there are still references on it. In this case, AVStream removed Item from *ObjectBag*, but did not free it regardless of the value of *Free*.

## Remarks

**KsRemoveItemFromObjectBag** frees *Item* only if the number of references on this item is zero and a free was requested.

For more information about object bags, see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags).

Note that the mutex associated with the bag must be held. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag)

[KsAllocateObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectbag)

[KsCopyObjectBagItems](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscopyobjectbagitems)

[KsDiscard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdiscard)

[KsFreeObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectbag)

[KsMergeAutomationTables](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmergeautomationtables)