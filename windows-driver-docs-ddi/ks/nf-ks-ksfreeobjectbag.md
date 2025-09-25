# KsFreeObjectBag function

## Description

The **KsFreeObjectBag** function empties and frees an object bag.

## Parameters

### `ObjectBag` [in]

The KSOBJECT_BAG (equivalent to type PVOID) to be emptied and then freed.

## Remarks

For more information, see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags).

**KsFreeObjectBag** removes any items present in *ObjectBag*. In addition, if the reference count for a given object is zero (that is, the object is not present in any other object bag associated with the same device as *ObjectBag*), then that item is freed.

## See also

[KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag)

[KsAllocateObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectbag)

[KsCopyObjectBagItems](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscopyobjectbagitems)

[KsDiscard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdiscard)

[KsRemoveItemFromObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremoveitemfromobjectbag)