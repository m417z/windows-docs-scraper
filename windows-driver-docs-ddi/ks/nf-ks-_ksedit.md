# _KsEdit function

## Description

The **KsEdit** function guarantees that a given item is dynamically allocated and associated with an AVStream object through the object bag.

## Parameters

### `ObjectBag` [in]

The KSOBJECT_BAG (equivalent to type PVOID) to use in the check. If the item is not contained within the object bag, **KsEdit** dynamically allocates sufficient memory for the item, copies the old contents, and places the newly allocated memory in this object bag.

### `PointerToPointerToItem` [in, out]

A pointer to a pointer to the item being edited.

### `NewSize` [in]

The number of bytes to allocate for the item.

### `OldSize` [in]

The number of bytes the item currently takes up.

### `Tag` [in]

Contains the pool tag to use for the allocations. Drivers normally specify the pool tag as a string of up to four characters, delimited by single quotation marks. The string is usually specified in reversed order. The ASCII value of each character in the tag must be between 0 and 127.

## Return value

Returns success or STATUS_INSUFFICIENT_RESOURCES.

## Remarks

Note that **KsEdit** and **KsEditSized** are macros created to make **_KsEdit** easier to use. While **_KsEdit** allows you to resize an item, **KsEdit** does not. The macro **KsEdit** calls **_KsEdit**, specifying **sizeof**(** *PointerToPointerToItem*) as both sizes.

For example, consider a pin that needs to modify its allocator framing on creation. Because the descriptor is statically coded and new pins may use it, the solution is to modify the pin descriptor as follows:

```cpp
KsEdit(Pin, &Pin->Descriptor, Tag);
Pin->Descriptor->AllocatorFraming = NewAllocatorFraming;
```

The call to **KsEdit** guarantees that *Pin->Descriptor* is dynamic memory that is associated with *Pin*. Note that arbitrary modification of descriptors and other AVStream structures can cause undesirable results. Minidrivers should exercise caution when using **KsEdit** on AVStream structures.

**KsEditSized** calls **_KsEdit** with the same parameters it receives, except that *Object* is replaced by *Object->Bag* and the pointer is typecast to PVOID.

Note that when calling **_KsEdit**, a caller must hold the mutex associated with the bag. For more information, see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags) and [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).