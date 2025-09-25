# KsAddItemToObjectBag function

## Description

The **KsAddItemToObjectBag** function adds an object or block of memory to the given object bag.

## Parameters

### `ObjectBag` [in]

The KSOBJECT_BAG (equivalent to type PVOID) to which to add the requested item. Every AVStream object (for example, [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) and [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)) contains a member called *Bag*. Pass that member in this parameter.

### `Item` [in]

A pointer to the item to add to the object bag.

### `Free` [in, optional]

A function that is called when the item is removed from the object bag or when the object bag is deleted. This function typically is used to free any dynamic memory associated with *Item*. The function should be prototyped as follows:

```cpp
void Free (IN PVOID Data);
```

If the caller does not specify this optional parameter, *Item* is freed with [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) when removed from the object bag or when the object bag is deleted.

## Return value

Either returns STATUS_SUCCESS indicating that the addition went normally or STATUS_INSUFFICIENT_RESOURCES indicating that there are insufficient system resources for the operation to proceed.

## Remarks

Before calling **KsAddItemToObjectBag**, the minidriver must acquire the mutex associated with the specific object bag. If *ObjectBag* is a member of a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) or [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory), acquire the device mutex. If the bag is a member of a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter), acquire the filter control mutex. If the bag is a member of a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) object, acquire the parent KSFILTER's filter control mutex.

For more information, see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags) and [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[KsAllocateObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectbag)

[KsCopyObjectBagItems](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscopyobjectbagitems)

[KsDiscard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdiscard)

[KsFreeObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectbag)

[KsRemoveItemFromObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremoveitemfromobjectbag)

[_KsEdit](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-_ksedit)