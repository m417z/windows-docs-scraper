# KsAllocateObjectBag function

## Description

The **KsAllocateObjectBag** function creates an object bag and associates it with a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice).

## Parameters

### `Device` [in]

A pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) representing the device object associated with the newly created object bag.

### `ObjectBag` [out]

A pointer to a KSOBJECT_BAG (the KSOBJECT_BAG structure is equivalent to type PVOID) where the newly allocated object bag is deposited.

## Return value

Returns STATUS_SUCCESS if a new object bag is created. If a new object bag is not allocated, it returns STATUS_INSUFFICIENT_RESOURCES.

## Remarks

An allocated object bag is not deleted automatically. The minidriver calling **KsAllocateObjectBag** is responsible for deletion of the object bag. The easiest way to do this is by calling [KsFreeObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectbag). Alternatively, if the minidriver has the addresses of the items in the bag, the minidriver can delete them individually by calling [KsRemoveItemFromObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremoveitemfromobjectbag).

For more information, see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags).

## See also

[KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag)

[KsCopyObjectBagItems](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscopyobjectbagitems)

[KsDiscard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdiscard)

[KsFreeObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectbag)

[KsRemoveItemFromObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremoveitemfromobjectbag)