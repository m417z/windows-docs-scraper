# WdfCollectionGetCount function

## Description

[Applies to KMDF and UMDF]

The **WdfCollectionGetCount** method returns the number of objects that are currently in an object collection.

## Parameters

### `Collection` [in]

A handle to a collection object.

## Return value

**WdfCollectionGetCount** returns the number of objects that are in the collection.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about object collections, see [Framework Object Collections](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-collections).

#### Examples

The following code example obtains the number of objects in a specified collection and uses the number to examine all objects in the collection.

```cpp
ULONG count;

count = WdfCollectionGetCount(CollectionHandle);
for (i = 0; i < count; i++) {
    ObjectHandle = WdfCollectionGetItem(
                                        CollectionHandle,
                                        i
                                        );
    //
    // Perform object-specific operations.
    //
}
```

## See also

[WdfCollectionGetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetitem)