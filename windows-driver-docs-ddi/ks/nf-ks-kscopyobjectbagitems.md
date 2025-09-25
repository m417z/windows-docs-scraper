# KsCopyObjectBagItems function

## Description

The **KsCopyObjectBagItems** function copies all items from one object bag into another.

## Parameters

### `ObjectBagDestination` [in]

The KSOBJECT_BAG (equivalent to type PVOID) into which to copy items.

### `ObjectBagSource` [in]

The KSOBJECT_BAG from which items are copied to *ObjectBagDestination.*

## Return value

Returns STATUS_SUCCESS if the copy is successful. Otherwise, it returns an error code. Most often, this is STATUS_INSUFFICIENT_RESOURCES indicating insufficient system resources to complete the copy operation. If STATUS_INSUFFICIENT_RESOURCES is returned, it is quite possible that some, but not all, of the items have been copied from *ObjectBagSource* to *ObjectBagDestination*.

## Remarks

Note that mutexes for both bags should be held. If the object bag in question is associated with a filter or a pin, acquire the filter control mutex. If the object bag belongs to a filter factory or the device, acquire the device mutex. For more information, see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags) and [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag)

[KsAllocateObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectbag)

[KsDiscard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdiscard)

[KsFreeObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectbag)

[KsPinGetConnectedFilterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedfilterinterface)

[KsPinGetConnectedPinInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedpininterface)

[KsPinGetReferenceClockInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetreferenceclockinterface)

[KsPinSetPinClockTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsetpinclocktime)

[KsRemoveItemFromObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremoveitemfromobjectbag)

[_KsEdit](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-_ksedit)